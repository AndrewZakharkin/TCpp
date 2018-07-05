//
// Created by andre on 04.07.2018.
//

#ifndef FIRSTTEST_BUILDER_H
#define FIRSTTEST_BUILDER_H

#include <tuple>
#include "Node.h"

class Builder {
public:
    std::pair<Node *, std::array<Node *, 6>> buildGraph();
};


#endif //FIRSTTEST_BUILDER_H
