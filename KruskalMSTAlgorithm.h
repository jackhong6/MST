//
// Created by jackh on 2020-05-06.
//

#ifndef MST_KRUSKALMSTALGORITHM_H
#define MST_KRUSKALMSTALGORITHM_H

#include "Graph.h"
#include <vector>

class KruskalMSTAlgorithm {
public:
    explicit KruskalMSTAlgorithm(Graph g, bool solve=false);
    void doKruskalMSTAlgorithm();
    int getMstCost();
    std::vector<Graph::Edge> getMstEdges();
private:
    std::vector<int> mstEdgeIndices;
    std::vector<Graph::Edge> graphEdges; // sorted by increasing cost on construction
    int numNodes;
    bool solved;
    static bool edgeComparator(Graph::Edge e1, Graph::Edge e2);
    int mstCost;
};


#endif //MST_KRUSKALMSTALGORITHM_H
