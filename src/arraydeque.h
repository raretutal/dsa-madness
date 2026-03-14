#ifndef ARRAYDEQUE_H
#define ARRAYDEQUE_H

#include "../include/list.h"
#include <algorithm>
#include <stdexcept>

template <typename T>
class ArrayDeque : public List<T> {
private:
    T* array;
    int start;
    int n;
    int cap;

    //indexing helper: for cleaner code
    int index(int i) const {
        return (start + i) % cap;
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
    ArrayDeque() : array(new T[1]), start(0), n(0), cap(1) {}

    ~ArrayDeque() {
        delete[] array;
    }

    T get(int i) const override {
        if (i < 0 || i >= n) throw std::out_of_range("Index out of bounds");
        return array[index(i)];
    }

    T set(int i, T x) override {
        if (i < 0 || i >= n) throw std::out_of_range("Index out of bounds");
        T old = array[index(i)]; 
        array[index(i)] = x; 
        return old;
    }

    void add(int i, T x) override {
        if (i < 0 || i > n) throw std::out_of_range("Index out of bounds");
        
        if (n + 1 > cap) resize();

        if (i < n / 2) { 
            // shift elements to the left 
            start = (start == 0) ? cap - 1 : start - 1;
            for (int k = 0; k < i; k++) 
                array[index(k)] = array[index(k + 1)];
        } else {
            // shift elements to the right
            for (int k = n; k > i; k--)
                array[index(k)] = array[index(k - 1)];
        }

        array[index(i)] = x;
        n++;
    }

    T remove(int i) override {
        if (i < 0 || i >= n) throw std::out_of_range("Index out of bounds");
        
        T x = array[index(i)];

        if (i < n / 2) {
            // shift elements to the right
            for (int k = i; k > 0; k--)
                array[index(k)] = array[index(k - 1)];
            start = (start + 1) % cap;
        } else {
            // shift elements to the left
            for (int k = i; k < n - 1; k++)
                array[index(k)] = array[index(k + 1)];
        }

        n--;
        if (3 * n <= cap) resize();
        return x;
    }

    int size() const override { return n; }
    bool isEmpty() const override { return n == 0; }
};

#endif