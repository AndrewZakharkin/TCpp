//
// Created by andre on 04.07.2018.
//

#include "Builder.h"
#include <iostream>

std::pair<Node*, std::array<Node*, 6>> Builder::buildGraph() {
    //std::list<Node> flatList;// = new ArrayList<>();
    //First Node

    Node * root = new Node("root");


    //adding 2 neighbours
    Node *rn1 = new Node("rn1");

    rn1->addNodeWithWeight(root, 5);//backward
    Node * rn2 = new Node("rn2");

    rn2->addNodeWithWeight(root, 2);//backward
    root->addNodesWithWeights(std::valarray<Node*>({rn1, rn2}),  std::valarray<int>({5, 2}));

    Node * rn1n1 = new Node("rn1n1");

    rn1->addNodeWithWeight(rn1n1, 3);
    rn1n1->addNodeWithWeight(rn1, 3);//backward

    Node * rn2n1 = new Node("rn2n1");

    Node * rn2n2 = new Node("rn2n2");

    rn2n1->addNodeWithWeight(rn2, 3);//backward
    rn2n2->addNodeWithWeight(rn2, 1);//backward
    rn2->addNodesWithWeights(std::valarray<Node*>({rn2n1, rn2n2}), std::valarray<int>({3, 1}));

    rn1n1->addNodeWithWeight(rn2n2, 1);
    rn2n2->addNodeWithWeight(rn1n1, 1);

    rn1n1->addNodeWithWeight(rn2n1, 1);
    rn2n1->addNodeWithWeight(rn1n1, 1);

    rn2n1->addNodeWithWeight(rn2n2, 2);
    rn2n2->addNodeWithWeight(rn2n1, 2);

    std::array<Node*, 6> flatList = { root, rn1, rn2, rn1n1, rn2n1, rn2n2 };
    //print out neighbours count
    for(Node* node : flatList){
        std::cout << node->getName() << " has " << node->getNeighbours().size() << " neighbours: ";
        auto ws = node->getWeights();
        auto ns = node->getNeighbours();
        for(int i = 0; i < ws.size(); ++i){
            Node* neightbour = ns[i];
            std::cout << neightbour->getName() << " (" << ws[i] << ") ";

        }
        std::cout << std::endl;
        node->setWeight(2000000);
    }
    flatList[0]->setWeight(0);

    return std::pair<Node*, std::array<Node*, 6>>(root, std::move(flatList));
}
