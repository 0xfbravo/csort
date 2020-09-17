//
// Created by Fellipe Bravo on 14/09/20.
//

#ifndef CSORT_CORE_H
#define CSORT_CORE_H

enum listMode {Random = 0, Ascending = 1, Descending = 2};
char* getListModeName(enum listMode listMode);
int* createIntList(enum listMode mode, int size);
void printIntList(int* list, int size);

#endif //CSORT_CORE_H
