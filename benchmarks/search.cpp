#include <iostream>
#include <chrono>
#include <iomanip>
#include "../src/arraydeque.h"
#include "../src/dllist.h"
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
    cout << "Benchmark Type: Search (" << N << " item lookups)" << endl << endl;
    cout << left << setw(25) << "ADT" << "Time(s)" << endl;
    cout << "----------------------------------------" << endl;

    ArrayDeque<int> aDeque;
    DLList<int> dlList;
    RedBlackTree<int> rbTree;
    SkipList<int> sList;
    ChainedHashTable<int> chTable;

    // Setup: Populate the ADTs that support searching
    for (int i = 0; i < N; i++) {
        aDeque.addLast(i);
        dlList.addLast(i);
        rbTree.add(i);
        sList.add(i);
        chTable.add(i);
    }

    // We only benchmark data structures that have search/contains methods
    cout << left << setw(25) << "ArrayDeque" 
         << measureTime([&]() { for (int i = 0; i < N; i++) aDeque.contains(i); }) << endl;

    cout << left << setw(25) << "DLList" 
         << measureTime([&]() { for (int i = 0; i < N; i++) dlList.count(i); }) << endl;

    cout << left << setw(25) << "RedBlackTree" 
         << measureTime([&]() { for (int i = 0; i < N; i++) rbTree.contains(i); }) << endl;

    cout << left << setw(25) << "SkipList" 
         << measureTime([&]() { for (int i = 0; i < N; i++) sList.contains(i); }) << endl;

    cout << left << setw(25) << "ChainedHashTable" 
         << measureTime([&]() { for (int i = 0; i < N; i++) chTable.contains(i); }) << endl;

    return 0;
}