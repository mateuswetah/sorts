#include "sort-selection.h"
#include "troca.h"
#include <stdio.h>
#include <stdlib.h>

int merge (int **vetor, int inicio, int meio, int fim, int* comparacoes, int* trocas)
{
	int i, m, k;
	int* intercalado;
	k = 0;
	i = inicio;
	m = meio + 1;
	intercalado = (int*) malloc( (fim - inicio + 1) * sizeof(int) );

	if (intercalado != NULL) {

		while (i <= meio && m <= fim) {
			if ( (*vetor)[i] < (*vetor)[m] ) {
				intercalado[k] = (*vetor)[i];
				i++;
			} else {
				intercalado[k] = (*vetor)[m];
				m++;
			}
			k++;
			*comparacoes = *comparacoes + 1;
		}
		while (i <= meio) {
			intercalado[k] = (*vetor)[i];
			i++;
			k++;
			*comparacoes = *comparacoes + 1;
		}
		while (m <= fim) {
			intercalado[k] = (*vetor)[m];
			m++;
			k++;
			*comparacoes = *comparacoes + 1;
		}
		
		for (k = inicio; k <= fim; k++) {
			(*vetor)[k] = intercalado[k-inicio];
			*trocas = *trocas + 1;
		}
	}

	free(intercalado);

}

void merge_sort (int **vetor, int inicio, int fim, int* comparacoes, int* trocas)
{

	if (inicio < fim)
	{
		int meio = (inicio + fim) / 2;

		// Etapa de divisão dos dados
		merge_sort(vetor, inicio, meio, comparacoes, trocas);
		merge_sort(vetor, meio + 1, fim, comparacoes, trocas);
		
		// Etapa de combinação dos dados
		merge(vetor, inicio, meio, fim, comparacoes, trocas);
	}

	return;
}