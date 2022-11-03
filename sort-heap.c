#include "sort-heap.h"
#include "troca.h"

#define PAI (i/2)
#define ESQ (2*i)
#define DIR (2*i + 1)

void max_heapfy (int **vetor, int i, int n) 
{
	int esq = ESQ;
	int dir = DIR;
	int maior;

	if ( (esq < n) && ((*vetor)[esq] > (*vetor)[i]) )
		maior = esq;
	else
		maior = i;

	if ( (dir < n) && ((*vetor)[dir] > (*vetor)[maior]) )
		maior = dir;

	if (maior != i) 
	{	
		troca(&(*vetor)[i], &(*vetor)[maior]);
		max_heapfy(vetor, maior, n);
	}

	return;
}

void constroi_heap (int **vetor, int n) 
{
	int i;

	for (i = n/2 - 1; i >= 0; i--)
		max_heapfy(vetor, i, n);

	return;
}

void heap_sort (int **vetor, int n)
{
	int i;

	constroi_heap(vetor, n);

	for (i = n - 1; i > 0; i--)
	{
		troca(&(*vetor)[i], &(*vetor)[0]);
		max_heapfy(vetor, 0, --n);
	}

}