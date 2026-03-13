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
        arr = new T[capacity];
    }

    ~ArrayStack() {
        delete[] arr;
    }

    void push(T x) override {
        if (n == capacity) {
            resize(capacity * 2);   // grow
        }
        arr[n++] = x;
    }

    T pop() override {
        if (n == 0) {
            throw std::out_of_range("Stack empty");
        }

        T val = arr[--n];

        // shrink if too empty
        if (n > 0 && n <= capacity / 4) {
            resize(capacity / 2);
        }

        return val;
    }

    T top() override {
        if (n == 0) {
            throw std::out_of_range("Stack empty");
        }
        return arr[n - 1];
    }

    // access element inside stack
    T peekAt(int index) {
        if (index < 0 || index >= n) {
            throw std::out_of_range("Invalid index");
        }
        return arr[index];
    }

    int size() override {
        return n;
    }

    bool isEmpty() override {
        return n == 0;
    }
};

#endif