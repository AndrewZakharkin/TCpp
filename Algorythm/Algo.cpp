//
// Created by andre on 04.07.2018.
//

#include "Algo.h"

void Algo::runAlgo(Node *currentNode) {
    if(currentNode->isVisited())
        return;
    std::vector<Node*> neighbours = currentNode->getNeighbours();
    std::vector<int> weights = currentNode->getWeights();

    currentNode->setVisited(true);
    int baseWeight = currentNode->getWeight();

    for(int i = 0; i < neighbours.size(); ++i){

        int curWeight = neighbours[i]->getWeight();
        if(curWeight > (baseWeight + weights[i])){
            curWeight = baseWeight + weights[i];
            neighbours[i]->setVisited(false);
        }
        neighbours[i]->setWeight(curWeight);
    }
    for(int i = 0; i < neighbours.size(); ++i){
        if(!neighbours[i]->isVisited()){
            runAlgo(neighbours[i]);
        }
    }
}
