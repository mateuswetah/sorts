#include "sort-selection.h"
#include "troca.h"

int particiona_quick (int **vetor, int ini, int fim)
{
	int chave, i, j;

	chave = (*vetor)[fim];
	i = ini - 1;

	for (j = ini; j <= fim - 1; j++)
	{
		if ((*vetor)[j] <= chave)
		{
			i++;
			troca(&(*vetor)[j], &(*vetor)[i]);
		}
	} 

	troca(&(*vetor)[fim], &(*vetor)[i+1]);

	return (i + 1);

}

void quick_sort (int **vetor, int ini, int fim)
{
	int chave;

	if (ini < fim)
	{
		chave = particiona_quick(vetor, ini, fim);
		quick_sort(vetor, ini, chave - 1);
		quick_sort(vetor, chave + 1, fim);
	}

	return;
}