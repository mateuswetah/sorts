#include "sort-selection.h"
#include "troca.h"

int particiona_quick (int **vetor, int inicio, int fim, int* comparacoes, int* trocas)
{

	int pivo = (*vetor)[inicio];
	int esq = inicio;
	int dir = fim;

	while (esq < dir) {
		*comparacoes = *comparacoes + 1;

		while ( (*vetor)[esq] <= pivo ) {
			*comparacoes = *comparacoes + 1;
			esq++;
		}
		while ( (*vetor)[dir] > pivo ) {
			*comparacoes = *comparacoes + 1;
			dir--;
		}

		*comparacoes = *comparacoes + 1;
		if (esq < dir) {
			troca(&(*vetor)[esq], &(*vetor)[dir]);
			*trocas = *trocas + 1;
		}
	}

	troca(&(*vetor)[inicio], &(*vetor)[dir]);
	*trocas = *trocas + 1;

	return dir;

}

void quick_sort (int **vetor, int inicio, int fim, int* comparacoes, int* trocas)
{

	if (inicio < fim)
	{
		int p = particiona_quick(vetor, inicio, fim, comparacoes, trocas);
		quick_sort(vetor, inicio, p - 1, comparacoes, trocas);
		quick_sort(vetor, p + 1, fim, comparacoes, trocas);
	}

	return;
}