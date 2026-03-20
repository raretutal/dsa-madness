#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include "../src/meldableheap.h"

using namespace std;
using namespace std::chrono;

const int N = 100000000;

template <typename Func>
double measureTime(Func f) {
    auto start = high_resolution_clock::now();
    f();
    auto end = high_resolution_clock::now();
    return duration<double>(end - start).count();
}

int main() {
    srand(123);
    int* randomPriorities = new int[N];
    for (int i = 0; i < N; i++) {
        randomPriorities[i] = rand() % (N * 2);
    }

    cout << "Benchmark Type: Priority Task Scheduling (" << N << " random tasks)" << endl << endl;
    cout << left << setw(25) << "Phase" << "Time(s)" << endl;
    cout << "----------------------------------------" << endl;

    MeldableHeap<int> mHeap;

    cout << left << setw(25) << "Task Queueing (Insert)" 
         << measureTime([&]() { 
             for (int i = 0; i < N; i++) mHeap.add(randomPriorities[i]); 
         }) << endl;

    cout << left << setw(25) << "Task Processing (Extract)" 
         << measureTime([&]() { 
             while (!mHeap.isEmpty()) mHeap.remove(); 
         }) << endl;

    delete[] randomPriorities;
    return 0;
}