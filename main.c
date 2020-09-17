#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "core/core.h"
#include "sort/sort.h"

int main(int argc, char **argv) {

	// Arguments validation
	if (argc != 4) {
		fprintf(stderr, "O programa não pode ser executado pois os parâmetros estão errados\n");
		fprintf(stderr, "Para a execução é necessário passar: ./main (ordenacaoLista) (tamanhoLista) (algoritmo)\n");
		fprintf(stderr, "Exemplo: ./csort 0 1000 0\n");
		return EXIT_FAILURE;
	}

	// Starts time measuring
	clock_t start = clock();

	// Reads list mode and size from user input
	int listMode = strtol(argv[1], NULL, 10);
	int listSize = strtol(argv[2], NULL, 10);
	int algorithm = strtol(argv[3], NULL, 10);

	char* listModeString = getListModeName(listMode);
	char* algorithmString = getAlgorithmName(algorithm);

	// List creation
	printf("[%s] Lista %s...\n", algorithmString, listModeString);
	int* list = createIntList(listMode, listSize);

	// Algorithm execution
	sortIntList(list, listSize, algorithm);

	// Remove list from memory
	free(list);

	// Stops measuring time and calculate the elapsed time
	clock_t end = clock();
	double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Tempo de execução: %.8f segundos.\n", elapsed);

	return EXIT_SUCCESS;
}
