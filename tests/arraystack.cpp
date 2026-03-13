#include <iostream>
#include "../src/arraystack.h"

using namespace std;

int main() {
    ArrayStack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;

    // pop elements
    while (!s.isEmpty()) {
        cout << "Popped: " << s.pop() << endl;
    }

    cout << "Stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

return 0;
}
