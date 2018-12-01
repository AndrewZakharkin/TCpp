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
            //neighbours[i]->setVisited(false);
        }
        neighbours[i]->setWeight(curWeight);
    }
    Node * nextToCheck = nullptr;
    do{
        nextToCheck = getNearestUnvisitedNeighbour(currentNode);
        if(nextToCheck){
            runAlgo(nextToCheck);
        }
    }while(nextToCheck);
}

Node *Algo::getNearestUnvisitedNeighbour(Node *node) {
    //std::vector<Node *> getNeighbours();
    //    std::vector<int> getWeights();
    std::vector<Node*> ns = node->getNeighbours();
    std::vector<int> ws = node->getWeights();
    Node * result = nullptr;
    int minWeight = 10000000;
    for(int i = 0; i < ns.size(); ++i){
        if(ws[i] < minWeight && !ns[i]->isVisited()){
            minWeight = ws[i];
            result = ns[i];
        }
    }
    return result;
}
