//
// Created by andre on 04.07.2018.
//

#ifndef FIRSTTEST_ALGO_H
#define FIRSTTEST_ALGO_H


#include <array>
#include "Node.h"

class Algo {
public:
    Algo(Node *root, std::array<Node*, 6> lst):rootNode(root), flatList(lst){};
    void runAlgo(Node* currentNode);
private:
    Node * getNearestUnvisitedNeighbour(Node * node);
    Node * rootNode;
    std::array<Node*, 6> flatList;
};


#endif //FIRSTTEST_ALGO_H
