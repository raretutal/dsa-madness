#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include "../include/graph.h"
#include <vector>
#include <stdexcept>

class AdjacencyMatrix : public Graph {
private:
    int numVertices;
    bool** matrix; // 2D array to represent edges

    // Helper to prevent out-of-bounds memory access
    void validateVertex(int v) const {
        if (v < 0 || v >= numVertices) {
            throw std::out_of_range("Vertex out of bounds");
        }
    }

public:
    AdjacencyMatrix(int vertices) {
        numVertices = vertices;
        matrix = new bool*[numVertices];
        
        for (int i = 0; i < numVertices; i++) {
            matrix[i] = new bool[numVertices]{false}; // Initialize all edges to false
        }
    }

    ~AdjacencyMatrix() {
        for (int i = 0; i < numVertices; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void addEdge(int i, int j) override {
        validateVertex(i);
        validateVertex(j);
        matrix[i][j] = true;
    }

    void removeEdge(int i, int j) override {
        validateVertex(i);
        validateVertex(j);
        matrix[i][j] = false;
    }

    bool hasEdge(int i, int j) const override {
        validateVertex(i);
        validateVertex(j);
        return matrix[i][j];
    }

    std::vector<int> outEdges(int i) const override {
        validateVertex(i);
        std::vector<int> edges;
        for (int j = 0; j < numVertices; j++) {
            if (matrix[i][j]) {
                edges.push_back(j);
            }
        }
        return edges;
    }

    std::vector<int> inEdges(int i) const override {
        validateVertex(i);
        std::vector<int> edges;
        for (int j = 0; j < numVertices; j++) {
            if (matrix[j][i]) {
                edges.push_back(j);
            }
        }
        return edges;
    }

    int getNumVertices() const override {
        return numVertices;
    }
};

#endif