//
// Created by andre on 01.12.2018.
//

#include "SimpleNode.h"

void SimpleNode::addNode(SimpleNode *child) {
    children.push_back(child);
}

std::vector<SimpleNode *> &SimpleNode::getChildren() {
    return children;
}

int SimpleNode::getValue() {
    return val;
}

void SimpleNode::setValue(int val){
    this->val = val;
}
