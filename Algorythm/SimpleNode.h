//
// Created by andre on 01.12.2018.
//

#ifndef FIRSTTEST_SIMPLENODE_H
#define FIRSTTEST_SIMPLENODE_H


#include <vector>

class SimpleNode {
public:
    SimpleNode() { }

    SimpleNode(int v) : val(v) {}

    void addNode(SimpleNode*child);
    std::vector<SimpleNode*>& getChildren();
    void setValue(int val);
    int getValue();
private:
    std::vector<SimpleNode*> children;
    int val;
};


#endif //FIRSTTEST_SIMPLENODE_H
