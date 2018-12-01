//
// Created by andre on 01.08.2018.
//

#include <iostream>
#include <vector>
#include "QuickSortInt.h"

int QuickSortInt::cnt = 1;

QuickSortInt::QuickSortInt(std::vector<int> &unsorted, int size) : unsorted(unsorted) {
    this->unsorted = unsorted;
    this->size = size;
}

void QuickSortInt::sort() {
    int start = 0;
    int end = size - 1;
    int level = 1;
    sortImpl(start, end, &level);
    std::cout << std::endl << level << std::endl;
}

std::vector<int>& QuickSortInt::getArray() {
    return unsorted;
}

int QuickSortInt::getSize() {
    return size;
}

void QuickSortInt::sortImpl(int start, int end, int*level) {
    if(start >= end)
        return;

    if(start == (end - 1)){
        if(unsorted[start] > unsorted[end]){
            int tmp = unsorted[start];
            unsorted[start] = unsorted[end];
            unsorted[end] = tmp;
        }
        return;
    }
    int pivotIdx = end;
    int pivot = unsorted[pivotIdx];
    std::cout << "pivot:" << pivot << std::endl;
    int i = start - 1;
    for(int j = start; j < end; ++j) {
        if (unsorted[j] <= pivot) {
            ++i;
            int tmp = unsorted[j];
            unsorted[j] = unsorted[i];
            unsorted[i] = tmp;
        }//swap A[i] with A[j]
    }
    int tmp = unsorted[i + 1];
    unsorted[i + 1] = unsorted[end];
    unsorted[end] = tmp;
    //swap A[i + 1] with A[hi]
    *level = *level + 1;
    printSlice(start, i);
    std::cout << i << std::endl;
    printSlice(i + 1, end);
    sortImpl(start, i, level);

    sortImpl(i + 1, end, level);
}

void QuickSortInt::printSlice(int start, int end) {
    QuickSortInt::cnt++;
    //if(QuickSortInt::cnt>50)
        //throw QuickSortInt::cnt;
    std::cout << "start:" << start << " - end:" << end << std::endl;
    for(int i = start; i < end; ++i){
        std::cout << unsorted[i] << "|";
    }
    std::cout << std::endl;
}
