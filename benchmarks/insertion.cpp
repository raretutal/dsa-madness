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
    cout << "Benchmark Type: Insertion (" << N << " items)" << endl << endl;
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

    cout << left << setw(25) << "ArrayStack" 
         << measureTime([&]() { for (int i = 0; i < N; i++) aStack.push(i); }) << endl;

    cout << left << setw(25) << "SLList (Queue)" 
         << measureTime([&]() { for (int i = 0; i < N; i++) slList.add(i); }) << endl;

    cout << left << setw(25) << "MeldableHeap" 
         << measureTime([&]() { for (int i = 0; i < N; i++) mHeap.add(i); }) << endl;

    cout << left << setw(25) << "DequeArray" 
         << measureTime([&]() { for (int i = 0; i < N; i++) dqArray.pushBack(i); }) << endl;

    cout << left << setw(25) << "ArrayDeque" 
         << measureTime([&]() { for (int i = 0; i < N; i++) aDeque.addLast(i); }) << endl;

    cout << left << setw(25) << "DLList" 
         << measureTime([&]() { for (int i = 0; i < N; i++) dlList.addLast(i); }) << endl;

    cout << left << setw(25) << "RedBlackTree" 
         << measureTime([&]() { for (int i = 0; i < N; i++) rbTree.add(i); }) << endl;

    cout << left << setw(25) << "SkipList" 
         << measureTime([&]() { for (int i = 0; i < N; i++) sList.add(i); }) << endl;

    cout << left << setw(25) << "ChainedHashTable" 
         << measureTime([&]() { for (int i = 0; i < N; i++) chTable.add(i); }) << endl;

    return 0;
}