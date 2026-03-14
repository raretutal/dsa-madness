#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    virtual ~Graph() {}

    // Adds a directed edge from vertex i to vertex j
    virtual void addEdge(int i, int j) = 0;

    // Removes the directed edge from vertex i to vertex j
    virtual void removeEdge(int i, int j) = 0;

    // Checks if there is an edge from vertex i to vertex j
    virtual bool hasEdge(int i, int j) const = 0;

    // Returns a list of all vertices that vertex i points to
    virtual std::vector<int> outEdges(int i) const = 0;

    // Returns a list of all vertices that point to vertex i
    virtual std::vector<int> inEdges(int i) const = 0;

    // Gets the total number of vertices in the graph
    virtual int getNumVertices() const = 0;
};

#endif