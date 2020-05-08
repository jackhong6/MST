//
// Created by jackh on 2020-05-05.
//

#include "Graph.h"
#include <fstream>
#include <iostream>
#include <iomanip>

Graph::Graph(const std::string& filename) {
    std::ifstream dataFile(filename);
    int nNodes;
    dataFile >> nNodes;
    adjacencyMatrix = std::vector<std::vector<int>> (nNodes, std::vector<int>(nNodes));

    int node1, node2, cost;
    while (dataFile >> node1 >> node2 >> cost) {
        addEdge(node1, node2, cost);
    }
}

void Graph::addEdge(int node1, int node2, int cost) {
    edgeVec.push_back(Edge{node1, node2, cost});
    adjacencyMatrix[node1][node2] = adjacencyMatrix[node2][node1] = cost;
}

int Graph::getNumNodes() {
    return adjacencyMatrix.size();
}

std::ostream &operator<<(std::ostream &os, const Graph &g) {
    std::cout << "The adjacency matrix of this graph is:" << std::endl;
    // print column labels
    std::cout << "     ";
    for (int i=0; i<g.adjacencyMatrix.size(); ++i) {
        std::cout << std::setw(2) << i << "\t";
    }
    std::cout << std::endl << "     ";
    for (int i=0; i<g.adjacencyMatrix.size(); ++i) {
        std::cout << "--" << "\t";
    }
    std::cout << std::endl;

    // print rows
    int row = 0;
    for (auto &vec : g.adjacencyMatrix) {
        std::cout << std::setw(2) << row++ << " | ";
        for (auto &n : vec) {
            std::cout << std::setw(2) << n << "\t";
        }
        std::cout << std::endl;
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, const Graph::Edge &edge) {
    std::cout << "(" << std::setw(2) << edge.node1 << ") ---- "
        << edge.cost << " ---- (" << std::setw(2) << edge.node2 << ")";
}

std::vector<Graph::Edge> Graph::getEdgeVec() {
    return edgeVec;
}
