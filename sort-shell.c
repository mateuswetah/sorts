#include "sort-shell.h"
#include "troca.h"

void shell_sort (int **vetor, int n)
{
	int i, j, chave, incremento = 1;

	while (incremento < n)
		incremento = 3*incremento + 1;

	while (incremento > 1)
	{
		incremento /= 3;

		for (i = incremento; i < n; i++)
		{
	 		chave = (*vetor)[i];
			j = i - incremento;

			while (j >= 0 && chave < (*vetor)[j])
			{
				(*vetor)[j + incremento] = (*vetor)[j];
				j -= incremento;
			}

			(*vetor)[j + incremento] = chave;
		}
	}
}