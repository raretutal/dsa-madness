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