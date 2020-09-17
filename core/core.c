//
// Created by Fellipe Bravo on 14/09/20.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "core.h"

/**
 * Returns a string related to list mode
 * enum.
 * @param listMode
 * @return the list mode name
 */
char* getListModeName(enum listMode listMode) {
	switch (listMode) {
		case Random:
			return "Randômica";
		case Ascending:
			return "Em ordem crescente";
		case Descending:
			return "Em ordem decrescente";
		default:
			fprintf(stderr, "Modo de criação de lista inválido!\n");
			fprintf(stderr, "Opções válidas: {Randomico = 0, Crescente = 1, Decrescente = 2}\n");
			return "";
	}
}

/**
 * Allocates the memory for an integers
 * list of a certain size
 * @param size
 * @return a new empty list
 */
int* initEmptyIntList(int size) {
	return malloc(sizeof(int) * size);
}

/**
 * Creates a random integers list
 * @param size
 * @return a desceding integer list
 */
int* randomIntList(int size) {
	int* list = initEmptyIntList(size);
	for (int i = 0; i < size; i++) {
		list[i] = rand();
	}
	return list;
}

/**
 * Creates an ascending integer list
 * @param size
 * @return a ascending integer list
 */
int* ascendingIntList(int size) {
	int* list = initEmptyIntList(size);
	for (int i = 0; i < size; i++) {
		list[i] = i;
	}
	return list;
}

/**
 * Creates a descending integer list
 * @param size
 * @return a descending integer list
 */
int* descendingIntList(int size) {
	int* list = initEmptyIntList(size);
	for (int i = size; i > 0; i--) {
		list[size-i] = i;
	}
	return list;
}

/**
 * Creates a list with N numbers,
 * and you can choose how numbers are inserted
 * in this new list.
 * Using random value (mode: 0),
 * ascending values (mode: 1) or
 * descending values (mode: 2).
 * Check `listMode` enum
 * @param mode
 * @param size
 * @return a new integer list according to specifications
 */
int* createIntList(enum listMode mode, int size) {
	switch (mode) {
		case Random:
			return randomIntList(size);
		case Ascending:
			return ascendingIntList(size);
		case Descending:
			return descendingIntList(size);
		default:
			fprintf(stderr, "Modo de criação de lista inválido!\n");
			return NULL;
	}
}

/**
 * Prints a certain list on console
 * @param intArray
 * @param maxSize
 */
void printIntList(int* intList, int size) {
	for (int i = 0; i < size; i++) {
		printf("[%d]", intList[i]);
	}
	printf("\n");
}
