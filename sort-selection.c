#include "sort-selection.h"
#include "troca.h"

/**
 * @brief A "Ordenação por Seleção" (Selection Sort) divide o vetor
 * em uma parte ordenada, à esquerda do elemento analisado, e uma
 * ainda desordenada, à direita deste. Para cada elemento do vetor,
 * o algoritmo procura na parte não ordenada o menor valor
 * (ordenação crescente) e troca os dois valores de lugar.
 * Avança-se então o elemento analisado, repetindo a mesma lógica.
 * 
 * @param vetor - vetor de inteiros que será ordenado
 * @param n - tamanho do vetor, quantidade de elementos
 */
void selection_sort (int** vetor, int n, int* comparacoes, int* trocas)
{
	int i, j, menor;

	for (i = 0; i < (n - 1); i++)
	{
		menor = i;

		for (j = (i + 1); j < n; j++)
		{
			*comparacoes = *comparacoes + 1;

			if ( (*vetor)[j] < (*vetor)[menor] ) 
				menor = j;			
		}

		if (i != menor) {
			troca(&(*vetor)[i], &(*vetor)[menor]);
			
			*trocas = *trocas + 1;
		}

	/* Alternativa estavel, porem menos eficiente */
	/*
		int chave = (*vetor)[menor];
        while (menor > i)
        {
            (*vetor)[menor] = (*vetor)[menor - 1];
            menor--;
        }
        (*vetor)[i] = chave;
	*/
	}

	return;
}