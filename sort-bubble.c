#include "sort-bubble.h"
#include "troca.h"

/**
 * @brief A ordenação por troca/bolha (Bubble Sort) funciona
 * com - a troca - par a par de todos os elementos do array,
 * verificando se o elemento ao seu lado é maior/menor do
 * que o atual.
 * 
 * @param vetor - vetor de inteiros que será ordenado
 * @param n - tamanho do vetor, quantidade de elementos
 */
void bubble_sort (int** vetor, int n, int* comparacoes, int* trocas)
{
	int i, j;

    for (i = 0; i < (n - 1); i++)
	{
		char trocou = 0;

        for (j = 0; j < (n - i - 1); j++)
		{
			*comparacoes = *comparacoes + 1;

            if ( (*vetor)[j] > (*vetor)[j + 1] ) {
            	troca(&(*vetor)[j], &(*vetor)[j+1]);
				trocou = 1;

				*trocas = *trocas + 1;
			}
		}
		
		if ( trocou == 0 )
			break;
	}

	return;
}