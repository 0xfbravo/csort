//
// Created by Fellipe Bravo on 14/09/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void printAlgorithmError() {
	fprintf(stderr, "Algoritmo inválido!\n");
	fprintf(stderr, "Opções válidas: {BubbleSort = 0, SelectionSort = 1, InsertionSort = 2, MergeSort = 3, QuickSortDefault = 4, QuickSortQSort = 5}\n");
}

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
			printAlgorithmError();
			return "";
	}
}

/**
 * Swap two integers
 * @param xp
 * @param yp
 */
void swap(int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * Executes the BubbleSort algorithm
 * @param list
 * @param size
 */
void bubbleSort(int* list, int size) {
	for (int i = 0; i < size-1; i++) {
		for (int j = 0; j < size-i - 1; j++) {
			if (list[j] > list[j + 1]) {
				swap(&list[j], &list[j + 1]);
			}
		}
	}
}

/**
 * Executes the InsertionSort algorithm
 * @param list
 * @param size
 */
void insertionSort(int* list, int size) {
	int i, key, j;
	for (i = 1; i < size; i++) {
		key = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > key) {
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
	}
}

/**
 * Sorts a list with N numbers,
 * and you can choose what sort algorithm should
 * be used according to algorithms list.
 * Check `algorithms`
 * @param list
 * @param size
 * @param mode
 * @return a new integer list according to specifications
 */
void sortIntList(int* list, int size, enum algorithm algorithm) {
	switch (algorithm) {
		case BubbleSort:
			bubbleSort(list, size);
			break;
		case InsertionSort:
			insertionSort(list, size);
			break;
		default:
			printAlgorithmError();
			break;
	}
}