#include <iostream>
#include <stdexcept>
#include "../src/arraydeque.h"

using namespace std;

int main() {
    ArrayDeque<int> ad;

    cout << "--- Array Deque Runner ---" << endl;

    // Test Adding
    cout << "Adding elements to the list..." << endl;
    ad.add(0, 10);
    ad.add(1, 30);
    ad.add(1, 20);

    cout << "Current List Size: " << ad.size() << endl;
    cout << "Element at index 0: " << ad.get(0) << endl;
    cout << "Element at index 1: " << ad.get(1) << endl;
    cout << "Element at index 2: " << ad.get(2) << endl;

    // Helper methods
    cout << "Adding 5 to the front and 40 to the back..." << endl;
    ad.addFirst(5);
    ad.addLast(40);

    cout << "New Size: " << ad.size() << endl;
    cout << "New First Element: " << ad.get(0) << endl;

    // Test Setting
    cout << "Changing index 2 from " << ad.get(2) << " to 99..." << endl;
    ad.set(2, 99);
    cout << "Current index 2: " << ad.get(2) << endl;

    // Test Removal
    cout << "Removing element at index 1 (value " << ad.get(1) << ")..." << endl;
    int removed = ad.remove(1);
    cout << "Removed value: " << removed << endl;
    cout << "List Size after removal: " << ad.size() << endl;

    // Test removeFirst / removeLast
    cout << "Remove first: " << ad.removeFirst() << endl;
    cout << "Remove last: " << ad.removeLast() << endl;

    // Test bulk insert (triggers resize)
    cout << "Bulk inserting 20 elements..." << endl;
    for (int i = 0; i < 20; i++) ad.addLast(i * 10);
    cout << "Size after bulk add: " << ad.size() << endl;

    // Twist: print
    cout << "Printing all elements:" << endl;
    ad.print();

    // Twist: indexOf
    cout << "indexOf(30): " << ad.indexOf(30) << endl;
    cout << "indexOf(999): " << ad.indexOf(999) << endl;

    // Twist: contains
    cout << "contains(30): " << (ad.contains(30) ? "Yes" : "No") << endl;
    cout << "contains(999): " << (ad.contains(999) ? "Yes" : "No") << endl;

    // Test exception handling
    cout << "Attempting to access invalid index 100..." << endl;
    try {
        ad.get(100);
    } catch (const out_of_range& e) {
        cout << "Caught Expected Error: " << e.what() << endl;
    }

    // Final
    cout << "List empty? " << (ad.isEmpty() ? "Yes" : "No") << endl;
    cout << "--- Array Deque Tests Completed ---" << endl;

    return 0;
}