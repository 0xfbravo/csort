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
 * Executes the SelectionSort algorithm
 * @param list
 * @param size
 */
void selectionSort(int* list, int size) {
	for (int i = 0; i < size-1; i++) {
		int minimumIndex = i;
		for (int j = i+1; j < size; j++) {
			if (list[j] < list[minimumIndex]) {
				minimumIndex = j;
			}
		}
		swap(&list[minimumIndex], &list[i]);
	}
}

/**
 * Executes the InsertionSort algorithm
 * @param list
 * @param size
 */
void insertionSort(int* list, int size) {
	for (int i = 1; i < size; i++) {
		int key = list[i];
		int j = i - 1;
		while (j >= 0 && list[j] > key) {
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
	}
}

/**
 * Part of MergeSort algorithm to
 * merge left and right sub-lists.
 * @param list
 * @param left
 * @param leftCount
 * @param right
 * @param rightCount
 */
void merge(int* list, int* left, int leftCount, int* right, int rightCount) {
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < leftCount && j < rightCount) {
		if (left[i] < right[j]) {
			list[k++] = left[i++];
		}
		else {
			list[k++] = right[j++];
		}
	}

	while (i < leftCount) {
		list[k++] = left[i++];
	}

	while (j < rightCount){
		list[k++] = right[j++];
	}
}

/**
 * Executes the MergeSort algorithm
 * @param list
 * @param size
 */
void mergeSort(int* list, int size) {
	if(size < 2) {
		return;
	}

	int half = size/2;
	int* left = malloc(half * sizeof(int));
	int* right = malloc((size - half) * sizeof(int));

	for (int i = 0; i < half; i++) {
		left[i] = list[i];
	}

	for (int i = half; i < size; i++) {
		right[i-half] = list[i];
	}

	mergeSort(left, half);
	mergeSort(right, size-half);
	merge(list, left, half, right, size - half);
	free(left);
	free(right);
}

/**
 * Sorts a list with N numbers,
 * and you can choose what sort algorithm should
 * be used according to algorithms list.
 * Check `algorithms` enum
 * @param list
 * @param size
 * @param algorithm
 * @return a sorted integer list
 */
void sortIntList(int* list, int size, enum algorithm algorithm) {
	switch (algorithm) {
		case BubbleSort:
			bubbleSort(list, size);
			break;
		case InsertionSort:
			insertionSort(list, size);
			break;
		case SelectionSort:
			selectionSort(list, size);
			break;
		case MergeSort:
			mergeSort(list, size);
			break;
		default:
			printAlgorithmError();
			break;
	}
}