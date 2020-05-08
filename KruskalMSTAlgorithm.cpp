//
// Created by jackh on 2020-05-06.
//
// Use Kruskal's algorithm to find the minimum spanning tree of a given graph.
// Based on the pseudocode found on Wikipedia: https://en.wikipedia.org/wiki/Kruskal%27s_algorithm

#include "KruskalMSTAlgorithm.h"
#include "UnionFindDisjointSet.h"
#include <algorithm>

KruskalMSTAlgorithm::KruskalMSTAlgorithm(Graph g, bool solve) : solved(false), mstCost(0), mstEdgeIndices(0){
    numNodes = g.getNumNodes();
    graphEdges = g.getEdgeVec();
    std::sort(graphEdges.begin(), graphEdges.end(), edgeComparator);
    if (solve) doKruskalMSTAlgorithm();
}

bool KruskalMSTAlgorithm::edgeComparator(Graph::Edge e1, Graph::Edge e2) {
    return e1.cost < e2.cost;
}

void KruskalMSTAlgorithm::doKruskalMSTAlgorithm() {
    UnionFindDisjointSet disjointSet(numNodes);
    mstCost = 0;
    mstEdgeIndices.clear();
    int edgeInd = 0;
    int numEdgesInMST = 0;
    // graphEdges sorted in order of increasing cost on instantiation
    for (auto edge : graphEdges) {
        if (!disjointSet.isSameSet(edge.node1, edge.node2)) {
            mstEdgeIndices.push_back(edgeInd);
            mstCost += edge.cost;
            if (++numEdgesInMST == numNodes - 1) break; // the tree is now spanning
            disjointSet.unionByRank(edge.node1, edge.node2);
        }
        edgeInd++;
    }

    solved = true;
}

int KruskalMSTAlgorithm::getMstCost() {
    if (!solved) doKruskalMSTAlgorithm();
    return mstCost;
}

std::vector<Graph::Edge> KruskalMSTAlgorithm::getMstEdges() {
    if (!solved) doKruskalMSTAlgorithm();
    std::vector<Graph::Edge> mstEdges;
    for (auto ind : mstEdgeIndices) {
        mstEdges.push_back(graphEdges.at(ind));
    }
    return mstEdges;
}


