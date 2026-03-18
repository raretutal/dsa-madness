#include <iostream>
#include <stdexcept>
#include "../src/dllist.h"

using namespace std;

int main() {
    DLList<int> dl;

    cout << "--- DLList Runner ---" << endl;

    // Test Adding
    cout << "Adding elements to the list..." << endl;
    dl.add(0, 10);
    dl.add(1, 30);
    dl.add(1, 20);

    cout << "Current List Size: " << dl.size() << endl;
    cout << "Element at index 0: " << dl.get(0) << endl;
    cout << "Element at index 1: " << dl.get(1) << endl;
    cout << "Element at index 2: " << dl.get(2) << endl;

    // Helper methods
    cout << "Adding 5 to the front and 40 to the back..." << endl;
    dl.addFirst(5);
    dl.addLast(40);

    cout << "New Size: " << dl.size() << endl;
    cout << "New First Element: " << dl.get(0) << endl;

    // Test Setting
    cout << "Changing index 2 from " << dl.get(2) << " to 99..." << endl;
    dl.set(2, 99);
    cout << "Current index 2: " << dl.get(2) << endl;

    // Test Removal
    cout << "Removing element at index 1 (value " << dl.get(1) << ")..." << endl;
    int removed = dl.remove(1);
    cout << "Removed value: " << removed << endl;
    cout << "List Size after removal: " << dl.size() << endl;

    // Test removeFirst / removeLast
    cout << "Remove first: " << dl.removeFirst() << endl;
    cout << "Remove last: " << dl.removeLast() << endl;

    // Twist: print
    cout << "Printing all elements:" << endl;
    dl.print();

    // Twist: printReverse
    cout << "Printing in reverse:" << endl;
    dl.printReverse();

    // Twist: count
    DLList<int> c;
    c.addLast(10);
    c.addLast(20);
    c.addLast(10);
    c.addLast(30);
    c.addLast(10);
    cout << "count(10) in [10, 20, 10, 30, 10]: " << c.count(10) << endl;
    cout << "count(999): " << c.count(999) << endl;

    // Test exception handling
    cout << "Attempting to access invalid index 100..." << endl;
    try {
        dl.get(100);
    } catch (const out_of_range& e) {
        cout << "Caught Expected Error: " << e.what() << endl;
    }

    // Final
    cout << "List empty? " << (dl.isEmpty() ? "Yes" : "No") << endl;
    cout << "--- DLList Tests Completed ---" << endl;

    return 0;
}