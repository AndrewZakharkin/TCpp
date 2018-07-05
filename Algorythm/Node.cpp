//
// Created by andre on 04.07.2018.
//

#include "Node.h"

void Node::addNodeWithWeight(Node *node, int weight) {
    neighbours.push_back(node);
    weights.push_back(weight);
}

void Node::addNodesWithWeights(std::valarray<Node*> nodes, std::valarray<int> weights) {
    for(Node * n : nodes) {
        neighbours.push_back(n);
    };
    for(int w : weights)
        this->weights.push_back(w);
}

std::vector<Node*> Node::getNeighbours() {
    return neighbours;
}

std::vector<int> Node::getWeights() {
    return weights;
}

bool Node::isVisited() {
    return _isVisited;
}

void Node::setVisited(bool visited) {
    this->_isVisited = visited;
}

int Node::getWeight() {
    return weight;
}

void Node::setWeight(int weight) {
    this->weight = weight;
}

std::string Node::getName() {
    return name;
}

Node::Node(Node &src) {
    neighbours = src.neighbours;
    weights = src.weights;
    _isVisited = src._isVisited;
    weight = src.weight;
    name = src.name;
}

Node::Node(Node &&src) {
    neighbours = std::move(src.neighbours);
    weights = std::move(src.weights);
    _isVisited = src._isVisited;
    weight = src.weight;
    name = std::move(src.name);
}
