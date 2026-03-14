#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "../include/stack.h"
#include <stdexcept>

template <typename T>
class ArrayStack : public Stack<T> {
private:
    T* arr;
    int capacity;
    int n;
    int pushCount;   //for the twist needed

    void resize(int newCap) {
        T* newArr = new T[newCap];

        for (int i = 0; i < n; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCap;
    }

public:
    ArrayStack(int initialCap = 8) {
        capacity = initialCap;
        n = 0;
        pushCount = 0;
        arr = new T[capacity];
    }

    ~ArrayStack() {
        delete[] arr;
    }

    void push(T x) override {
        pushCount++;

        if (n == capacity) {
            resize(capacity * 2);
        }

        // Twist: every 5th push inserts at the bottom this is slowerrr
        if (pushCount % 5 == 0) {
            for (int i = n; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = x;
            n++;
        }
        else {
            arr[n++] = x;
        }
    }

    T pop() override {
        if (n == 0) {
            throw std::out_of_range("Stack empty");
        }

        return arr[--n];
    }

    T top() override {
        if (n == 0) {
            throw std::out_of_range("Stack empty");
        }

        return arr[n - 1];
    }

    int size() override {
        return n;
    }

    bool isEmpty() override {
        return n == 0;
    }
};

#endif