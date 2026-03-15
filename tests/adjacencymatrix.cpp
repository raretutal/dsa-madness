#include <iostream>
#include <vector>
#include "../src/adjacencymatrix.h"

using namespace std;

int main() {
    cout << "--- Adjacency Matrix Graph Runner ---" << endl;

    int numVertices = 5;
    AdjacencyMatrix graph(numVertices);

    cout << "Graph initialized with " << graph.getNumVertices() << " vertices." << endl;

    // Test Adding Edges (Directed Graph)
    cout << "Adding edges..." << endl;
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Test Checking Edges
    cout << "Edge 0 -> 1? " << (graph.hasEdge(0, 1) ? "Yes" : "No") << endl;
    cout << "Edge 1 -> 0? " << (graph.hasEdge(1, 0) ? "Yes" : "No (Expected, edges are directed)") << endl;

    // Test Outgoing Edges
    cout << "Outgoing edges from vertex 1: ";
    vector<int> outEdges = graph.outEdges(1);
    for (int v : outEdges) {
        cout << v << " ";
    }
    cout << endl;

    // Test Incoming Edges
    cout << "Incoming edges to vertex 4: ";
    vector<int> inEdges = graph.inEdges(4);
    for (int v : inEdges) {
        cout << v << " ";
    }
    cout << endl;

    // Test Removing Edges
    cout << "Removing edge 1 -> 4..." << endl;
    graph.removeEdge(1, 4);
    cout << "Edge 1 -> 4? " << (graph.hasEdge(1, 4) ? "Yes" : "No") << endl;

    // Test Exception Handling for Out of Bounds
    try {
        cout << "Attempting to add edge to invalid vertex 10... ";
        graph.addEdge(0, 10);
    } catch (const out_of_range& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }

    cout << "--- Tests Completed Successfully ---" << endl;

    return 0;
}