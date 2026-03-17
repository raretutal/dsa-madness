#ifndef DLLIST_H
#define DLLIST_H

#include "../include/list.h"
#include <stdexcept>
#include <iostream>

template <typename T>
class DLList : public List<T> {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T val = T{}) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* sentinel;
    int n;

    // get node at index i from whichever end is closer
    Node* getNode(int i) const {
        Node* cur;
        if (i < n / 2) {
            cur = sentinel->next;
            for (int k = 0; k < i; k++)
                cur = cur->next;
        } else {
            cur = sentinel->prev;
            for (int k = n - 1; k > i; k--)
                cur = cur->prev;
        }
        return cur;
    }

    // insert newNode right before successor
    void insertBefore(Node* successor, Node* newNode) {
        newNode->next = successor;
        newNode->prev = successor->prev;
        successor->prev->next = newNode;
        successor->prev = newNode;
        n++;
    }

    // unlink and delete a node, return its value
    T unlink(Node* node) {
        T val = node->data;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        n--;
        return val;
    }

    // remove all real nodes without touching the dummy
    void clearAll() {
        Node* cur = sentinel->next;
        while (cur != sentinel) {
            Node* tmp = cur->next;
            delete cur;
            cur = tmp;
        }
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
        n = 0;
    }

public:
    DLList() : n(0) {
        sentinel = new Node();
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
    }

    ~DLList() {
        clearAll();
        delete sentinel;
    }

    T get(int i) const override {
        if (i < 0 || i >= n) throw std::out_of_range("Index out of bounds");
        return getNode(i)->data;
    }

    T set(int i, T x) override {
        if (i < 0 || i >= n) throw std::out_of_range("Index out of bounds");
        Node* node = getNode(i);
        T old = node->data;
        node->data = x;
        return old;
    }

    void add(int i, T x) override {
        if (i < 0 || i > n) throw std::out_of_range("Index out of bounds");
        Node* successor = (i == n) ? sentinel : getNode(i);
        insertBefore(successor, new Node(x));
    }

    T remove(int i) override {
        if (i < 0 || i >= n) throw std::out_of_range("Index out of bounds");
        return unlink(getNode(i));
    }

    int size() const override { return n; }
    bool isEmpty() const override { return n == 0; }

    // twist: prints all elements for debugging
    void print() const {
        Node* cur = sentinel->next;
        while (cur != sentinel) {
            std::cout << cur->data;
            if (cur->next != sentinel) std::cout << " <-> ";
            cur = cur->next;
        }
        std::cout << std::endl;
        std::cout << "size: " << n << std::endl;
    }

    // twist: prints all elements in reverse using prev pointers
    void printReverse() const {
        Node* cur = sentinel->prev;
        while (cur != sentinel) {
            std::cout << cur->data;
            if (cur->prev != sentinel) std::cout << " <-> ";
            cur = cur->prev;
        }
        std::cout << std::endl;
    }

    // twist: counts how many times x appears in the list
    int count(T x) const {
        int total = 0;
        Node* cur = sentinel->next;
        while (cur != sentinel) {
            if (cur->data == x) total++;
            cur = cur->next;
        }
        return total;
    }
};

#endif