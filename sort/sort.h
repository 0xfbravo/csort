//
// Created by Fellipe Bravo on 14/09/20.
//

#ifndef CSORT_SORT_H
#define CSORT_SORT_H

enum algorithm {BubbleSort = 0, SelectionSort = 1, InsertionSort = 2, MergeSort = 3, QuickSortDefault = 4, QuickSortQSort = 5};
char* getAlgorithmName(enum algorithm algorithm);
void sortIntList(int* list, int size, enum algorithm algorithm);

#endif //CSORT_SORT_H
