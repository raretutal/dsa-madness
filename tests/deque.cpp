#include <iostream>
#include <stdexcept>
#include "../src/dequearray.h"

using namespace std;

int main() {
    DequeArray<int> dq;

    cout << "--- DequeArray Runner ---" << endl << endl;

    dq.pushBack(20);
    dq.pushBack(30);
    dq.pushFront(10);
    cout << "After pushing 10, 20, 30:" << endl;
    dq.print();
    cout << "SIZE: " << dq.size() << " | FRONT: " << dq.peekFront() << " | BACK: " << dq.peekBack() << endl;

    cout << "\nPOP FRONT: " << dq.popFront() << " | POP BACK: " << dq.popBack() << endl;
    dq.print();

    int backArr[] = {10, 20, 30, 40, 50};
    dq.pushBackAll(backArr, 5);
    cout << "\nPUSHBACKALL: 10 20 30 40 50" << endl;
    dq.print();

    int frontArr[] = {3, 2, 1};
    dq.pushFrontAll(frontArr, 3);
    cout << "\nPUSHFRONTALL: 3 2 1" << endl;
    dq.print();

    DequeArray<int> empty;
    try { empty.popFront(); }
    catch (const underflow_error& e) { cout << "\nEXCEPTION: " << e.what() << endl; }

    cout << "\n--- DequeArray Tests Completed ---" << endl;

    return 0;
}