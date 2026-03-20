# 🚀 DSA Madness

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C++17-blue.svg)](https://isocpp.org/)
[![Status](https://img.shields.io/badge/Status-Active_Development-brightgreen.svg)]()

> A small, open-source C++ library of core Data Structures and Algorithms featuring unique implementation "twists" for educational benchmarking.

---

## 📖 Project Intro

**DSA Madness** is a custom-built, header-only C++ library of fundamental Abstract Data Types (ADTs) and their concrete implementations. Created as a final project for CMSC 123, this repository is designed to be an out-of-the-box, user-friendly collection of data structures written completely from scratch. 

### Key Features
* **Zero External Dependencies:** Pure C++ implementations relying only on standard libraries.
* **Educational "Twists":** Select data structures feature intentional quirks (e.g., node-caching in linked lists, $O(N)$ penalty operations in stacks, and batch insertions) to create fascinating profiling and benchmarking scenarios.
* **Interface-Driven Design:** Clean separation between abstract interfaces (`include/`) and concrete implementations (`src/`).

---

## 🧠 Core Technical Concepts & Inspiration

This project exists to explore the inner workings of data structures rather than relying on `std::vector` or `std::map`. By implementing structures like Red-Black Trees and Skip Lists from memory and logic, the library demonstrates key CS concepts:
* **Amortized Analysis:** Explored through dynamic array resizing in our Stack and Deque.
* **Probabilistic Balancing:** Demonstrated by the randomized heights in the Skip List.
* **Deterministic Balancing:** Showcased via the strict recoloring and rotation rules of the Red-Black Tree.

Unlike standard libraries built purely for speed, **DSA Madness** balances standard operations with deliberate "twists" to test edge cases in algorithmic complexity.

---

## 🚀 Getting Started

### Prerequisites
* A C++ compiler (GCC, Clang, or MSVC) supporting C++11 or higher.
* `make` (optional, for running tests and benchmarks).

### Installation
Since this is essentially a header-driven library, installation is as simple as cloning the repository and including the headers in your project.

```bash
# 1. Clone the repository
git clone [https://github.com/raretutal/dsa-madness.git](https://github.com/raretutal/dsa-madness.git)

# 2. Navigate to the project directory
cd dsa-madness
```
### Usage
Simply include the specific header from the src/directory into your C++ file
```cpp
#include "src/redblacktrees.h"
#include <iostream>

int main() {
    RedBlackTree<int> tree;
    tree.add(42);
    std::cout << "Contains 42? " << tree.contains(42) << std::endl;
    return 0;
}
```

## 🛠️ Abstract Data Types (ADTs) & API Reference

Below is the comprehensive list of every ADT and its available methods.

### **Stack** (Implemented via `ArrayStack`)
*Twist: Every 5th `push()` inserts the element at the absolute bottom of the stack, causing an $O(N)$ shift.*
* `push(T x)` - Adds element `x` to the top of the stack.
* `pop()` - Removes and returns the top element of the stack.
* `top()` - Returns the top element without removing it.
* `size()` - Returns the current number of elements in the stack.
* `isEmpty()` - Returns `true` if the stack contains no elements.

### **Queue** (Implemented via `SLList`)
*Twist: Caches a "spare" node upon removal to avoid frequent memory allocation on the next insertion.*
* `add(T x)` - Enqueues element `x` to the back of the queue.
* `remove()` - Dequeues and returns the element at the front.
* `peek()` - Returns the front element without removing it.
* `size()` - Returns the current number of elements in the queue.
* `isEmpty()` - Returns `true` if the queue contains no elements.

### **Priority Queue** (Implemented via `MeldableHeap`)
*Twist: Tracks subtree sizes and always merges the new node into the smaller subtree to keep the tree balanced.*
* `add(T x)` - Inserts element `x` into the priority queue.
* `remove()` - Removes and returns the smallest element (highest priority).
* `peek()` - Returns the smallest element without removing it.
* `size()` - Returns the current number of elements.
* `isEmpty()` - Returns `true` if the priority queue contains no elements.

### **Deque** (Implemented via `DequeArray`)
*Twist: Includes batch insertion methods and a formatted print debugger.*
* `pushFront(T x)` - Adds element `x` to the front of the deque.
* `pushBack(T x)` - Adds element `x` to the back of the deque.
* `popFront()` - Removes and returns the front element.
* `popBack()` - Removes and returns the back element.
* `peekFront()` - Returns the front element without removing it.
* `peekBack()` - Returns the back element without removing it.
* `pushBackAll(T* arr, int size)` - Batch inserts an array of elements to the back.
* `pushFrontAll(T* arr, int size)` - Batch inserts an array of elements to the front.
* `print()` - Prints all elements in order.
* `size()` - Returns the current number of elements.
* `isEmpty()` - Returns `true` if the deque contains no elements.

### **List** (Implemented via `ArrayDeque` & `DLList`)
*Twists: `DLList` supports reverse printing and element counting. `ArrayDeque` supports indexing and containment checks.*
* `get(int i)` - Returns the element at index `i`.
* `set(int i, T x)` - Replaces the element at index `i` with `x` and returns the old value.
* `add(int i, T x)` - Inserts element `x` at index `i`, shifting subsequent elements.
* `remove(int i)` - Removes and returns the element at index `i`.
* `addFirst(T x)` - Inserts element `x` at the beginning.
* `addLast(T x)` - Inserts element `x` at the end.
* `removeFirst()` - Removes and returns the first element.
* `removeLast()` - Removes and returns the last element.
* `print()` - Prints all elements in the list.
* `printReverse()` *(DLList only)* - Prints all elements in reverse order.
* `count(T x)` *(DLList only)* - Returns the number of times `x` appears in the list.
* `indexOf(T x)` *(ArrayDeque only)* - Returns the index of `x`, or `-1` if not found.
* `contains(T x)` *(ArrayDeque only)* - Returns `true` if `x` is in the list.

### **Sorted Set (SSet)** (Implemented via `SkipList` & `RedBlackTree`)
* `add(T x)` - Adds element `x` while maintaining sorted order. Returns `false` if `x` already exists.
* `remove(T x)` - Removes element `x`. Returns `false` if `x` was not found.
* `contains(T x)` - Returns `true` if `x` exists in the set.
* `size()` - Returns the current number of elements.

### **Unsorted Set (USet)** (Implemented via `ChainedHashTable`)
* `add(T x)` - Hashes and adds element `x`. Returns `false` if `x` already exists.
* `remove(T x)` - Removes element `x`. Returns `false` if `x` was not found.
* `contains(T x)` - Returns `true` if `x` exists in the table.
* `size()` - Returns the current number of elements.

### **Graph** (Implemented via `AdjacencyMatrix`)
* `addEdge(int i, int j)` - Adds a directed edge from vertex `i` to vertex `j`.
* `removeEdge(int i, int j)` - Removes the directed edge from vertex `i` to vertex `j`.
* `hasEdge(int i, int j)` - Returns `true` if an edge exists from `i` to `j`.
* `outEdges(int i)` - Returns a `std::vector<int>` of all vertices that vertex `i` points to.
* `inEdges(int i)` - Returns a `std::vector<int>` of all vertices that point to vertex `i`.
* `getNumVertices()` - Returns the total number of vertices in the graph.