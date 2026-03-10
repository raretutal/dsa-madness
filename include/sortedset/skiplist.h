// src/skiplist.h
#ifndef SKIPLIST_H
#define SKIPLIST_H

#include "./sset.h"
#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
class SkipList : public SSet<T> {
private:
    struct Node {
        T value;
        std::vector<Node*> next;
        Node(T val, int level) : value(val), next(level + 1, nullptr) {}
    };

    Node* head;
    int maxLevel;
    float probability;
    int n; // size

    int randomLevel() {
        int lvl = 0;
        while ((static_cast<float>(rand()) / RAND_MAX) < probability && lvl < maxLevel) {
            lvl++;
        }
        return lvl;
    }

public:
    SkipList(int maxLvl = 16, float prob = 0.5f) : maxLevel(maxLvl), probability(prob), n(0) {
        srand(static_cast<unsigned>(time(0)));
        // Head acts as a sentinel node (dummy node)
        head = new Node(T(), maxLevel); 
    }

    ~SkipList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next[0];
            delete temp;
        }
    }

    bool contains(T x) const override {
        Node* curr = head;
        for (int i = maxLevel; i >= 0; i--) {
            while (curr->next[i] != nullptr && curr->next[i]->value < x) {
                curr = curr->next[i];
            }
        }
        curr = curr->next[0];
        return curr != nullptr && curr->value == x;
    }

    bool add(T x) override {
        std::vector<Node*> update(maxLevel + 1, nullptr);
        Node* curr = head;

        for (int i = maxLevel; i >= 0; i--) {
            while (curr->next[i] != nullptr && curr->next[i]->value < x) {
                curr = curr->next[i];
            }
            update[i] = curr;
        }

        curr = curr->next[0];
        if (curr != nullptr && curr->value == x) {
            return false; // Already exists
        }

        int lvl = randomLevel();
        Node* newNode = new Node(x, lvl);
        for (int i = 0; i <= lvl; i++) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }
        n++;
        return true;
    }

    bool remove(T x) override {
        std::vector<Node*> update(maxLevel + 1, nullptr);
        Node* curr = head;

        for (int i = maxLevel; i >= 0; i--) {
            while (curr->next[i] != nullptr && curr->next[i]->value < x) {
                curr = curr->next[i];
            }
            update[i] = curr;
        }

        curr = curr->next[0];
        if (curr != nullptr && curr->value == x) {
            for (int i = 0; i <= maxLevel; i++) {
                if (update[i]->next[i] != curr) break;
                update[i]->next[i] = curr->next[i];
            }
            delete curr;
            n--;
            return true;
        }
        return false;
    }

    int size() const override {
        return n;
    }
};

#endif 