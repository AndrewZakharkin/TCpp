//
// Created by andre on 01.08.2018.
//

#ifndef FIRSTTEST_QUICKSORTINT_H
#define FIRSTTEST_QUICKSORTINT_H


class QuickSortInt {
public:
    QuickSortInt(std::vector<int> &unsorted, int size);
    void sort();
    std::vector<int>& getArray();
    int getSize();

private:
    std::vector<int> &unsorted;
    int size;
    void sortImpl(int start, int end, int*level);
    void printSlice(int start, int end);
    static int cnt;
};


#endif //FIRSTTEST_QUICKSORTINT_H
