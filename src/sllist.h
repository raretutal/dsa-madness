#ifndef SLLIST_H
#define SLLIST_H

#include "../include/queue.h"
#include <stdexcept>

template <typename T>
class SLList : public Queue<T> {
private:
    struct Node {
        T value;
        Node* next;
        Node(T v) : value(v), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    Node* spare;   // twist: reusable node
    int n;

public:
    SLList() {
        head = nullptr;
        tail = nullptr;
        spare = nullptr;
        n = 0;
    }

    ~SLList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        if (spare != nullptr) {
            delete spare;
        }
    }

    void add(T x) override { // enqueue
        Node* newNode;

        // twist: reuse node if available
        if (spare != nullptr) {
            newNode = spare;
            spare = nullptr;
            newNode->value = x;
            newNode->next = nullptr;
        } else {
            newNode = new Node(x);
        }

        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        n++;
    }

    T remove() override { // dequeue
        if (head == nullptr) {
            throw std::out_of_range("Queue empty");
        }

        Node* temp = head;
        T val = temp->value;

        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        // twist: store one spare node for reuse
        if (spare == nullptr) {
            spare = temp;
            spare->next = nullptr;
        } else {
            delete temp;
        }

        n--;
        return val;
    }

    T peek() override {
        if (head == nullptr) {
            throw std::out_of_range("Queue empty");
        }
        return head->value;
    }

    int size() override {
        return n;
    }

    bool isEmpty() override {
        return n == 0;
    }
};

#endif