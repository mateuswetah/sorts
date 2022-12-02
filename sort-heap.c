#include "sort-heap.h"
#include "troca.h"

#define PAI ( (i - 1) / 2 )
#define ESQ ( i * 2 + 1 )
#define DIR ( (i * 2 + 1) + 1 )

void max_heapfy (int **vetor, int i, int tam) {
	int maior = i;

	 // Estes dois IFs elegem o índice onde está o maior: no atual, no filho esquerdo ou no direito
	if ( (ESQ < tam) && ((*vetor)[ESQ] > (*vetor)[maior]) )
		maior = ESQ;
	if ( (DIR < tam) && ((*vetor)[DIR] > (*vetor)[maior]) )
		maior = DIR;

	if (maior != i) {
		troca(&(*vetor)[i], &(*vetor)[maior]);
		max_heapfy(vetor, maior, tam);
	}
}

void constroi_heap (int **vetor, int tam) {
	int i = tam - 1;

	for (i = PAI; i >= 0; i--)
		max_heapfy(vetor, i, tam);

	return;
}

void heap_sort (int **vetor, int tam) {
	int i;

	constroi_heap(vetor, tam);

	for (i = tam - 1; i > 0; i--)
	{
		troca(&(*vetor)[i], &(*vetor)[0]);
		tam--;
		max_heapfy(vetor, 0, tam);
	}
}