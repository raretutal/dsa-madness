
#ifndef REDBLACKTREES_H
#define REDBLACKTREES_H

#include "../include/sset.h"

enum Color { RED, BLACK };

template <typename T>
class RedBlackTree : public SSet<T> {
private:
    struct Node {
        T value;
        Color color;
        Node* left;
        Node* right;
        Node* parent;
        Node() : color(BLACK), left(nullptr), right(nullptr), parent(nullptr) {} // For NIL node
        Node(T val) : value(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node* root;
    Node* NIL; // Sentinel node to replace nullptrs, simplifying edge cases
    int n;

    // Rotates the subtree rooted at x to the left
    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != NIL) y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    // Rotates the subtree rooted at x to the right
    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != NIL) y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;
        y->right = x;
        x->parent = y;
    }

    // Fixes structural /color violations after a standard BST insertion
    void fixInsert(Node* k) {
        while (k->parent != nullptr && k->parent->color == RED) {
            if (k->parent == k->parent->parent->right) {
                Node* u = k->parent->parent->left; // uncle
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rotateRight(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rotateLeft(k->parent->parent);
                }
            } else {
                Node* u = k->parent->parent->right; // uncle
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        rotateLeft(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rotateRight(k->parent->parent);
                }
            }
            if (k == root) break;
        }
        root->color = BLACK;
    }

    // Helper to transplant subtrees during deletion
    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) root = v;
        else if (u == u->parent->left) u->parent->left = v;
        else u->parent->right = v;
        v->parent = u->parent;
    }

    // Finds the node with the minimum value in a given subtree
    Node* minimum(Node* node) {
        while (node->left != NIL) node = node->left;
        return node;
    }

    // Fixes structural/color violations after a node deletion
    void fixDelete(Node* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                Node* s = x->parent->right; // sibling
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(x->parent);
                    s = x->parent->right;
                }
                if (s->left->color == BLACK && s->right->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->right->color == BLACK) {
                        s->left->color = BLACK;
                        s->color = RED;
                        rotateRight(s);
                        s = x->parent->right;
                    }
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = BLACK;
                    rotateLeft(x->parent);
                    x = root;
                }
            } else {
                Node* s = x->parent->left; // sibling
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    rotateRight(x->parent);
                    s = x->parent->left;
                }
                if (s->right->color == BLACK && s->left->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->left->color == BLACK) {
                        s->right->color = BLACK;
                        s->color = RED;
                        rotateLeft(s);
                        s = x->parent->left;
                    }
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    rotateRight(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    void destroyTree(Node* node) {
        if (node != NIL) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    RedBlackTree() : n(0) {
        NIL = new Node();
        root = NIL;
    }

    ~RedBlackTree() {
        destroyTree(root);
        delete NIL;
    }

    bool contains(T x) const override {
        Node* curr = root;
        while (curr != NIL) {
            if (x == curr->value) return true;
            curr = (x < curr->value) ? curr->left : curr->right;
        }
        return false;
    }

    bool add(T x) override {
        if (contains(x)) return false;

        Node* node = new Node(x);
        node->left = NIL;
        node->right = NIL;

        Node* y = nullptr;
        Node* curr = root;

        while (curr != NIL) {
            y = curr;
            if (node->value < curr->value) curr = curr->left;
            else curr = curr->right;
        }

        node->parent = y;
        if (y == nullptr) root = node;
        else if (node->value < y->value) y->left = node;
        else y->right = node;

        if (node->parent == nullptr) {
            node->color = BLACK;
            n++;
            return true;
        }
        if (node->parent->parent == nullptr) {
            n++;
            return true;
        }

        fixInsert(node);
        n++;
        return true;
    }

    bool remove(T x) override {
        Node* z = root;
        while (z != NIL) {
            if (x == z->value) break;
            z = (x < z->value) ? z->left : z->right;
        }

        if (z == NIL) return false; // Element not found

        Node* y = z;
        Node* x_replace;
        Color y_original_color = y->color;

        if (z->left == NIL) {
            x_replace = z->right;
            transplant(z, z->right);
        } else if (z->right == NIL) {
            x_replace = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            y_original_color = y->color;
            x_replace = y->right;
            
            if (y->parent == z) {
                x_replace->parent = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        delete z;
        if (y_original_color == BLACK) {
            fixDelete(x_replace);
        }
        n--;
        return true;
    }

    int size() const override {
        return n;
    }
};

#endif 