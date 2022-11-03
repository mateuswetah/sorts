#include "sort-insertion.h"
#include "troca.h"

/**
 * @brief A "Ordenação por Inserção" (Insertion Sort) vai "criando"
 * um vetor ordenado a partir da inserção dos elementos já no seu
 * lugar ordenado. Ele vai retirando elementos da parte desordenada e procurando na ordenada onde devem ser inseridos. 
 * 
 * @param vetor - vetor de inteiros que será ordenado
 * @param n - tamanho do vetor, quantidade de elementos
 */
void insertion_sort(int** vetor, int n, int* comparacoes, int* trocas)
{
	int i, j;

	for (i = 1; i < n; i++)
	{
		for ( j = i; j > 0 && (*vetor)[j] < (*vetor)[j-1]; j-- ) {
			*comparacoes = *comparacoes + 1;

			troca(&(*vetor)[j], &(*vetor)[j-1]);

			*trocas = *trocas + 1;
		}
	}

	return;
}