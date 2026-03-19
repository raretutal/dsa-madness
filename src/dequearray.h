#ifndef DEQUEARRAY_H
#define DEQUEARRAY_H

#include "../include/deque.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>

template <typename T>
class DequeArray : public Deque<T> {
private:
    T* array;
    int start;
    int n;
    int cap;

    // wrapping helper
    int wrap(int i) const {
        return ((start + i) % cap + cap) % cap;
    }

    void resize() {
        int oldCap = cap;
        cap = std::max(2 * n, 1);
        T* newArray = new T[cap];

        for (int k = 0; k < n; k++) {
            newArray[k] = array[(start + k) % oldCap];
        }

        delete[] array;
        array = newArray;
        start = 0;
    }

public:
    DequeArray() : array(new T[1]), start(0), n(0), cap(1) {}

    ~DequeArray() {
        delete[] array;
    }

    void pushFront(T x) override {
        if (n + 1 > cap) resize();
        start = (start == 0) ? cap - 1 : start - 1;
        array[start] = x;
        n++;
    }

    void pushBack(T x) override {
        if (n + 1 > cap) resize();
        array[wrap(n)] = x;
        n++;
    }

    T popFront() override {
        if (n == 0) throw std::underflow_error("Deque is empty");
        T x = array[start];
        start = (start + 1) % cap;
        n--;
        if (3 * n <= cap) resize();
        return x;
    }

    T popBack() override {
        if (n == 0) throw std::underflow_error("Deque is empty");
        T x = array[wrap(n - 1)];
        n--;
        if (3 * n <= cap) resize();
        return x;
    }

    T peekFront() const override {
        if (n == 0) throw std::underflow_error("Deque is empty");
        return array[start];
    }

    T peekBack() const override {
        if (n == 0) throw std::underflow_error("Deque is empty");
        return array[wrap(n - 1)];
    }

    int size() const override { return n; }
    bool isEmpty() const override { return n == 0; }

    // twist: prints all elements for debugging
    void print() const {
        std::cout << "[";
        for (int k = 0; k < n; k++) {
            std::cout << array[wrap(k)];
            if (k < n - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }

    // twist: batch insert multiple elements to the back
    void pushBackAll(T* arr, int size) {
        if (n + size > cap) {
            int oldCap = cap;
            cap = std::max(2 * (n + size), 1);
            T* newArray = new T[cap];

            for (int k = 0; k < n; k++)
                newArray[k] = array[(start + k) % oldCap];
            delete[] array;
            array = newArray;
            start = 0;
        }
        for (int k = 0; k < size; k++) {
            array[wrap(n)] = arr[k];
            n++;
        }
    }

    // twist: batch insert multiple elements to the front
    void pushFrontAll(T* arr, int size) {
        if (n + size > cap) {
            int oldCap = cap;
            cap = std::max(2 * (n + size), 1);
            T* newArray = new T[cap];

            for (int k = 0; k < n; k++)
                newArray[k] = array[(start + k) % oldCap];
            delete[] array;
            array = newArray;
            start = 0;
        }
        for (int k = 0; k < size; k++) {
            start = (start == 0) ? cap - 1 : start - 1;
            array[start] = arr[k];
            n++;
        }
    }
};

#endif