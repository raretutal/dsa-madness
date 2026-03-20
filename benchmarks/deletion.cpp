#include <iostream>
#include <chrono>
#include <iomanip>
#include "../src/arraystack.h"
#include "../src/sllist.h"
#include "../src/meldableheap.h"
#include "../src/dequearray.h"
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
    cout << "Benchmark Type: Deletion (" << N << " items)" << endl << endl;
    cout << left << setw(25) << "ADT" << "Time(s)" << endl;
    cout << "----------------------------------------" << endl;

    ArrayStack<int> aStack;
    SLList<int> slList;
    MeldableHeap<int> mHeap;
    DequeArray<int> dqArray;
    ArrayDeque<int> aDeque;
    DLList<int> dlList;
    RedBlackTree<int> rbTree;
    SkipList<int> sList;
    ChainedHashTable<int> chTable;

    // Setup: Populate all ADTs first
    for (int i = 0; i < N; i++) {
        aStack.push(i);
        slList.add(i);
        mHeap.add(i);
        dqArray.pushBack(i);
        aDeque.addLast(i);
        dlList.addLast(i);
        rbTree.add(i);
        sList.add(i);
        chTable.add(i);
    }

    cout << left << setw(25) << "ArrayStack" 
         << measureTime([&]() { while (!aStack.isEmpty()) aStack.pop(); }) << endl;

    cout << left << setw(25) << "SLList (Queue)" 
         << measureTime([&]() { while (!slList.isEmpty()) slList.remove(); }) << endl;

    cout << left << setw(25) << "MeldableHeap" 
         << measureTime([&]() { while (!mHeap.isEmpty()) mHeap.remove(); }) << endl;

    cout << left << setw(25) << "DequeArray" 
         << measureTime([&]() { while (!dqArray.isEmpty()) dqArray.popBack(); }) << endl;

    cout << left << setw(25) << "ArrayDeque" 
         << measureTime([&]() { while (!aDeque.isEmpty()) aDeque.removeLast(); }) << endl;

    cout << left << setw(25) << "DLList" 
         << measureTime([&]() { while (!dlList.isEmpty()) dlList.removeLast(); }) << endl;

    cout << left << setw(25) << "RedBlackTree" 
         << measureTime([&]() { for (int i = 0; i < N; i++) rbTree.remove(i); }) << endl;

    cout << left << setw(25) << "SkipList" 
         << measureTime([&]() { for (int i = 0; i < N; i++) sList.remove(i); }) << endl;

    cout << left << setw(25) << "ChainedHashTable" 
         << measureTime([&]() { for (int i = 0; i < N; i++) chTable.remove(i); }) << endl;

    return 0;
}