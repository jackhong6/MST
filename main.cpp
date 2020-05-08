#include <iostream>
#include "Graph.h"
#include "KruskalMSTAlgorithm.h"
#include <vector>

int main() {
    Graph g("sampleMSTData.txt");
    KruskalMSTAlgorithm kMstAlgo = KruskalMSTAlgorithm(g, true);
    std::vector<Graph::Edge> mstEdges = kMstAlgo.getMstEdges();

    std::cout << "The total cost of the MST is: " << kMstAlgo.getMstCost() << std::endl;

    std::cout << "The edges in the MST are:" << std::endl;
    for (auto edge : mstEdges) {
        std::cout << edge << std::endl;
    }

    return 0;
}
