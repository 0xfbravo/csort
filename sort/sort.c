//
// Created by Fellipe Bravo on 14/09/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * Returns a string related to algorithm
 * enum.
 * @param algorithm
 * @return the algorithm name
 */
char* getAlgorithmName(enum algorithm algorithm) {
    switch (algorithm) {
        case BubbleSort:
            return "BubbleSort";
        case SelectionSort:
            return "SelectionSort";
        case InsertionSort:
            return "InsertionSort";
        case MergeSort:
            return "MergeSort";
        case QuickSortDefault:
            return "QuickSortDefault";
        case QuickSortQSort:
            return "QuickSortQSort";
        default:
            fprintf(stderr, "Algoritmo inválido!\n");
            fprintf(stderr, "Opções válidas: {BubbleSort = 0, SelectionSort = 1, InsertionSort = 2, MergeSort = 3, QuickSortDefault = 4, QuickSortQSort = 5}\n");
            return "";
    }
}