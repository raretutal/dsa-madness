#include <iostream>
#include "../src/chainedhashtable.h"

using namespace std;

int main() {
    ChainedHashTable<int> cht;

    cout << "--- Chained Hash Table Runner ---" << endl;

    // Test basic insertion
    cout << "Adding elements: 10, 20, 30, 15, 25..." << endl;
    cht.add(10);
    cht.add(20);
    cht.add(30);
    cht.add(15);
    cht.add(25);

    cout << "Current Hash Table Size: " << cht.size() << endl;

    // Test search functionality
    cout << "Contains 15? " << (cht.contains(15) ? "Yes" : "No") << endl;
    cout << "Contains 100? " << (cht.contains(100) ? "Yes" : "No") << endl;

    // Verify USet property (no duplicates)
    cout << "Attempting to add duplicate (20): " << (cht.add(20) ? "Success" : "Failed (Expected)") << endl;
    cout << "Hash Table Size after duplicate attempt: " << cht.size() << endl;

    // Test removal (handling pointer re-linking)
    cout << "Removing element 20..." << endl;
    cht.remove(20);
    cout << "Hash Table Size after removal: " << cht.size() << endl;
    cout << "Contains 20? " << (cht.contains(20) ? "Yes" : "No") << endl;

    // Test dynamic resizing
    cout << "Testing resize by adding bulk elements..." << endl;
    for(int i = 100; i < 120; i++) {
        cht.add(i);
    }
    cout << "Size after bulk add: " << cht.size() << endl;
    cout << "Contains 115? " << (cht.contains(115) ? "Yes" : "No") << endl;

    cout << "--- Tests Completed Successfully ---" << endl;

    return 0;
}