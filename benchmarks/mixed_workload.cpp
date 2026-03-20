#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include "../src/redblacktrees.h"
#include "../src/skiplist.h"
#include "../src/chainedhashtable.h"

using namespace std;
using namespace std::chrono;

const int N = 100000;

template <typename Func>
double measureTime(Func f) {
    auto start = high_resolution_clock::now();
    f();
    auto end = high_resolution_clock::now();
    return duration<double>(end - start).count();
}

int main() {
    srand(42); // Fixed seed for consistent benchmarks
    int* operations = new int[N];
    int* values = new int[N];
    
    for (int i = 0; i < N; i++) {
        operations[i] = rand() % 100; // 0-49: search, 50-74: insert, 75-99: delete
        values[i] = rand() % (N / 2);
    }

    cout << "Benchmark Type: Mixed Workload (50% Read, 25% Write, 25% Delete - " << N << " ops)" << endl << endl;
    cout << left << setw(25) << "ADT" << "Time(s)" << endl;
    cout << "----------------------------------------" << endl;

    RedBlackTree<int> rbTree;
    SkipList<int> sList;
    ChainedHashTable<int> chTable;

    // Pre-populate with some data
    for (int i = 0; i < N / 4; i++) {
        rbTree.add(i); sList.add(i); chTable.add(i);
    }

    auto runMixedWorkload = [&](auto& ds) {
        for (int i = 0; i < N; i++) {
            if (operations[i] < 50) ds.contains(values[i]);
            else if (operations[i] < 75) ds.add(values[i]);
            else ds.remove(values[i]);
        }
    };

    cout << left << setw(25) << "RedBlackTree" << measureTime([&]() { runMixedWorkload(rbTree); }) << endl;
    cout << left << setw(25) << "SkipList" << measureTime([&]() { runMixedWorkload(sList); }) << endl;
    cout << left << setw(25) << "ChainedHashTable" << measureTime([&]() { runMixedWorkload(chTable); }) << endl;

    delete[] operations;
    delete[] values;
    return 0;
}