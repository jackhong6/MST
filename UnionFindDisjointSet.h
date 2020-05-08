//
// Created by jackh on 2020-05-06.
//
// Union-find-disjoint-set of integers implemented with path splitting and union by rank. This data structure
// allows efficient (near constant time) union of subsets and determination of whether two elements are in the same set.
//
// Each element is simply numbered from 0 to n-1.
// Based on pseudo-code found on Wikipedia: https://en.wikipedia.org/wiki/Disjoint-set_data_structure

#ifndef MST_UNIONFINDDISJOINTSET_H
#define MST_UNIONFINDDISJOINTSET_H

#include <vector>

class UnionFindDisjointSet {
public:
    // Initialize the disjoint set such that each element is its own tree and all ranks are zero.
    explicit UnionFindDisjointSet(int nElements);

    // Find the representative element of the tree that elemInd belongs to with path splitting (make every node on the
    // path point to its grandparent).
    int findSet(int elemInd);

    // Join the trees containing elemInd1 and elemInd2 by attaching the root of the tree with less rank to the root of
    // the tree with greater rank.
    void unionByRank(int elemInd1, int elemInd2);

    // Use findSet() to determine if elemInd1 and elemInd2 belong to the same subset.
    bool isSameSet(int elemInd1, int elemInd2);
private:
    std::vector<int> parents;  // parent of a root is itself
    std::vector<int> ranks;    // provides an upper bound on the tree height
};

#endif //MST_UNIONFINDDISJOINTSET_H
