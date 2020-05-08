//
// Created by jackh on 2020-05-06.
//

#include "UnionFindDisjointSet.h"
#include <numeric>

UnionFindDisjointSet::UnionFindDisjointSet(int nElements) : ranks(nElements, 0), parents(nElements){
    std::iota(parents.begin(), parents.end(), 0);
}

int UnionFindDisjointSet::findSet(int elemInd) {
    while (parents.at(elemInd) != elemInd) {
        int nextInd = parents.at(elemInd);
        parents.at(elemInd) = parents.at(nextInd);
        elemInd = nextInd;
    }
    return elemInd;
}

void UnionFindDisjointSet::unionByRank(int elemInd1, int elemInd2) {
    int root1 = findSet(elemInd1);
    int root2 = findSet(elemInd2);

    if (root1 == root2) return; // elemInd1 and elemInd2 already belong to the same set.

    if (ranks.at(root1) < ranks.at(root2)) {
        parents.at(root1) = root2;
    }
    else if (ranks.at(root1) > ranks.at(root2)) {
        parents.at(root2) = root1;
    }
    else { // ranks[root1] == ranks[root2]
        parents.at(root2) = root1; // arbitrarily merge root2 into root1
        ++ranks.at(root1);
    }
}

bool UnionFindDisjointSet::isSameSet(int elemInd1, int elemInd2) {
    return findSet(elemInd1) == findSet(elemInd2);
}
