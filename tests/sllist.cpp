#include <iostream>
#include "../src/sllist.h"

using namespace std;

int main() {
    SLList<int> q;

    q.add(10);
    q.add(20);
    q.add(30);
    q.add(40);

    cout << "Front element: " << q.peek() << endl;
    cout << "Queue size: " << q.size() << endl;

    cout << "\nDequeuing elements:\n";

    while (!q.isEmpty()) {
        cout << q.remove() << endl;
    }

    cout << "\nQueue empty? ";
    cout << (q.isEmpty() ? "Yes" : "No") << endl;
return 0;
}
