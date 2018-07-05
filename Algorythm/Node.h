//
// Created by andre on 04.07.2018.
//

#ifndef FIRSTTEST_NODE_H
#define FIRSTTEST_NODE_H
#include <list>
#include <string>
#include <valarray>

class Node {
public:
    Node(std::string && name){
        neighbours = {};
        weights = {};
        this->name = std::move(name);
        _isVisited = false;
    }

    Node(const char * name) {
        neighbours = {};
        weights = {};
        this->name = name;
        _isVisited = false;
    }

    Node(Node & src);

    Node(Node && src);

    void addNodeWithWeight(Node * node, int weight);

    void addNodesWithWeights(std::valarray<Node*> nodes, std::valarray<int> weights);

    std::vector<Node *> getNeighbours();
    std::vector<int> getWeights();

    bool isVisited();

    void setVisited(bool visited);

    int getWeight();

    void setWeight(int weight);

    std::string getName();
private:
    std::vector<Node*> neighbours;
    std::vector<int> weights;
    bool _isVisited;
    int weight;
    std::string name;
};


#endif //FIRSTTEST_NODE_H
