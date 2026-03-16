#ifndef MELDABLEHEAP_H
#define MELDABLEHEAP_H

#include "../include/pqueue.h"
#include <stdexcept>

template <typename T>
class MeldableHeap : public PQueue<T> {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;
        int size;   // twist: track subtree size

        Node(T v) : value(v), left(nullptr), right(nullptr), size(1) {}
    };

    Node* root;
    int n;

    int getSize(Node* u) {
        return (u == nullptr) ? 0 : u->size;
    }

    void updateSize(Node* u) {
        if (u != nullptr) {
            u->size = 1 + getSize(u->left) + getSize(u->right);
        }
    }

    Node* merge(Node* h1, Node* h2) {
        if (h1 == nullptr) return h2;
        if (h2 == nullptr) return h1;

        if (h2->value < h1->value) {
            Node* temp = h1;
            h1 = h2;
            h2 = temp;
        }

        // twist: attach smaller subtree first
        if (getSize(h1->left) < getSize(h1->right)) {
            h1->left = merge(h1->left, h2);
        } else {
            h1->right = merge(h1->right, h2);
        }

        updateSize(h1);
        return h1;
    }

public:
    MeldableHeap() {
        root = nullptr;
        n = 0;
    }

    ~MeldableHeap() {
        clear(root);
    }

    void clear(Node* u) {
        if (u == nullptr) return;
        clear(u->left);
        clear(u->right);
        delete u;
    }

    void add(T x) override {
        Node* newNode = new Node(x);
        root = merge(root, newNode);
        n++;
    }

    T remove() override {
        if (root == nullptr) {
            throw std::out_of_range("Heap empty");
        }

        T val = root->value;
        Node* oldRoot = root;

        root = merge(root->left, root->right);

        delete oldRoot;
        n--;

        return val;
    }

    T peek() override {
        if (root == nullptr) {
            throw std::out_of_range("Heap empty");
        }
        return root->value;
    }

    int size() override {
        return n;
    }

    bool isEmpty() override {
        return n == 0;
    }
};

#endif