
#include <iostream>
#include "../src/redblacktrees.h"

using namespace std;

int main() {
    RedBlackTree<int> rbt;

    cout << "--- Red-Black Tree Runner ---" << endl;

    // Test Insertion
    cout << "Adding elements: 10, 20, 30, 15, 25..." << endl;
    rbt.add(10);
    rbt.add(20);
    rbt.add(30);
    rbt.add(15);
    rbt.add(25);

    cout << "Current Tree Size: " << rbt.size() << endl;

    // Test Contains
    cout << "Contains 15? " << (rbt.contains(15) ? "Yes" : "No") << endl;
    cout << "Contains 100? " << (rbt.contains(100) ? "Yes" : "No") << endl;

    // Test No Duplicates Property
    cout << "Attempting to add duplicate (20): " << (rbt.add(20) ? "Success" : "Failed (Expected)") << endl;
    cout << "Tree Size after duplicate attempt: " << rbt.size() << endl;

    // Test Removal
    cout << "Removing element 20..." << endl;
    rbt.remove(20);
    cout << "Tree Size after removal: " << rbt.size() << endl;
    cout << "Contains 20? " << (rbt.contains(20) ? "Yes" : "No") << endl;

    cout << "--- Tests Completed Successfully ---" << endl;

    return 0;
}