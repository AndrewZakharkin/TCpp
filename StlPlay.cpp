//
// Created by andre on 01.08.2018.
//

#include "StlPlay.h"
#include <bitset>
#include <iostream>
#include <limits>
#include <valarray>

void StlPlay::Play() {
    std::valarray<int> va(10);
    for(int i = 0; i < va.size(); ++i) {
        va[i] = i;
    }
    std::valarray<int> v2(va[va>4]);
    std::cout << v2.size() << std::endl;
    for(int i = 0; i < v2.size(); ++i) {
        std::cout << v2[i] << std::endl;
    }
}
