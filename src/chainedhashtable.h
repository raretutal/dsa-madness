#ifndef CHAINEDHASHTABLE_H
#define CHAINEDHASHTABLE_H

#include "../include/uset.h"
#include <functional> // for std::hash

template <typename T>
class ChainedHashTable : public USet<T> {
private:
    struct Node {
        T value;
        Node* next;
        Node(T val, Node* nxt = nullptr) : value(val), next(nxt) {}
    };

    Node** table;
    int capacity;
    int n;

    // Hashes value and ensures it fits within current capacity bounds
    size_t hash(T x) const {
        return std::hash<T>{}(x) % capacity;
    }

    // Doubles table capacity and rehashes all existing elements
    void resize() {
        int newCapacity = capacity * 2;
        Node** newTable = new Node*[newCapacity](); // zero-initialized

        // Reassign existing nodes to new table to avoid expensive allocations
        for (int i = 0; i < capacity; i++) {
            Node* curr = table[i];
            while (curr != nullptr) {
                Node* nextNode = curr->next;
                size_t newIdx = std::hash<T>{}(curr->value) % newCapacity;
                
                curr->next = newTable[newIdx];
                newTable[newIdx] = curr;
                
                curr = nextNode;
            }
        }

        delete[] table;
        table = newTable;
        capacity = newCapacity;
    }

public:
    ChainedHashTable(int initialCap = 8) : capacity(initialCap), n(0) {
        table = new Node*[capacity](); 
    }

    ~ChainedHashTable() {
        for (int i = 0; i < capacity; i++) {
            Node* curr = table[i];
            while (curr != nullptr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] table;
    }

    bool contains(T x) const override {
        size_t idx = hash(x);
        Node* curr = table[idx];
        while (curr != nullptr) {
            if (curr->value == x) return true;
            curr = curr->next;
        }
        return false;
    }

    bool add(T x) override {
        if (contains(x)) return false;

        if (n + 1 > capacity) {
            resize();
        }

        size_t idx = hash(x);
        table[idx] = new Node(x, table[idx]); // Insert at head of chain
        n++;
        return true;
    }

    bool remove(T x) override {
        size_t idx = hash(x);
        Node* curr = table[idx];
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->value == x) {
                if (prev == nullptr) {
                    table[idx] = curr->next; // Removing head of chain
                } else {
                    prev->next = curr->next; // Removing from middle/end
                }
                delete curr;
                n--;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    int size() const override {
        return n;
    }
};

#endif