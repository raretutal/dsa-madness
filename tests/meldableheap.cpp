#include <iostream>
#include "../src/meldableheap.h"

using namespace std;

int main() {
MeldableHeap<int> pq;

pq.add(40);
pq.add(10);
pq.add(30);
pq.add(20);
pq.add(5);

cout << "Min element: " << pq.peek() << endl;

cout << "\nRemoving elements:\n";

while (!pq.isEmpty()) {
    cout << pq.remove() << endl;
}

return 0;

}
