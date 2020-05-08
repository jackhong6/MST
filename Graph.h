//
// Created by jackh on 2020-05-05.
//
// Representation of a graph as an adjacency matrix.

#ifndef MST_GRAPH_H
#define MST_GRAPH_H

#include <vector>
#include <string>
#include <ostream>
#include <iostream>

class Graph {
public:
    explicit Graph(const std::string& filename); // may have to specify absolute path to text file depending on where the executable is run.
    class Edge {
    public:
        int node1, node2, cost;
        friend std::ostream& operator<<(std::ostream& os, const Edge &edge);
    };
    void addEdge(int node1, int node2, int weight);
    std::vector<Edge> getEdgeVec();
    int getNumNodes();
    friend std::ostream& operator<<(std::ostream& os, const Graph &g);

private:
    std::vector<Edge> edgeVec;
    std::vector<std::vector<int>> adjacencyMatrix;
};

#endif //MST_GRAPH_H
