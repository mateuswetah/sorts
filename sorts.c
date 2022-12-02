/**
 * @file 	  sorts.c
 * @author 	  Mateus Machado Luna (mateus_m_luna@ufg.br)
 * @brief 	  Este código foi feito para testar diferentes algorigmos de ordenacao.
 * 			  Como o codigo das ordenacoes esta em funcoes separadas, voce deve
 * 			  compilar este código usando: gcc -o sorts sorts.c sort-*.c troca.c
 * @version   0.1
 * @date 	  2022-10-29
 * @copyright Copyleft 2022
 */

// Includes comuns do C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importa algoritmos de ordenacao
#include "sort-bubble.h"
#include "sort-insertion.h"
#include "sort-selection.h"
#include "sort-shell.h"
#include "sort-quick.h"
#include "sort-merge.h"
#include "sort-heap.h"

// Preenche o vetor com valores randomicos
void gera_vetor_rand(int **vetor, int n)
{
	int i;

	for (i = 0; i < n; i++)
		(*vetor)[i] = 1 + (int)( (float) n*rand() / (RAND_MAX + 1.0) );
	
	return;	
}

// Exibe o vetor, separando cada item por espaco
void imprime_vetor(int **vetor, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d ", (*vetor)[i]);

	printf("\n");

	return;
}

// Funcao principal para testar ordenacoes
int main ()
{
	printf("TESTE DE ALGORITMOS DE ORDENAÇÃO\n");
	printf("--------------------------------\n");

	// Declaracao de variaveis
	int *vetor = NULL;
	int n, metodo, comparacoes = 0, trocas = 0;

	clock_t inicio, fim; // Especificas para medir
	double tempo_gasto;  // A duracao do programa

	// Le o tamanho do vetor
	printf("\nEntre com o tamanho do vetor aleatório: ");
	scanf("%d", &n);

	// Cria um vetor deste tamanho e preenche aleatoriamente
	vetor = (int*) malloc(n * sizeof(int));

	if (vetor != NULL) {
		gera_vetor_rand(&vetor, n);
		printf("Vetor gerado: ");
		imprime_vetor(&vetor, n);

		// Escolhe qual o tipo de ordenacao
		printf("\nEscolha um método de ordenação: \n");
		printf("1 - Bubble | 2 - Selection | 3 - Insertion | 4 - Shell \n5 - Merge | 6 - Quick | 7 - Heap\n");
		scanf("%d", &metodo);

		// Regiao de custo, medimos o tempo
		inicio = clock();

		switch (metodo)
		{
			case 2: selection_sort(&vetor, n, &comparacoes, &trocas);
			break;
			case 3: insertion_sort(&vetor, n, &comparacoes, &trocas);
			break;
			case 4: shell_sort(&vetor, n);
			break;
			case 5: merge_sort(&vetor, 0, n - 1, &comparacoes, &trocas);
			break;
			case 6: quick_sort(&vetor, 0, n - 1, &comparacoes, &trocas);
			break;
			case 7: heap_sort(&vetor, n);
			break;
			case 1: bubble_sort(&vetor, n, &comparacoes, &trocas);
			default:
			break;
		}

		fim = clock();

		// Fim da regiao de custo
		printf("Vetor ordenado: ");
		imprime_vetor(&vetor, n);

		tempo_gasto = (double)(fim - inicio)/CLOCKS_PER_SEC;
		printf("\nTempo = %lfs\n", tempo_gasto);

		// Se passado, mostra quantas comparacores foram feitas
		if ( comparacoes )
			printf("\nComparações = %d\n", comparacoes);
		
		// Se passado, mostra quantas trocas foram feitas
		if ( trocas )
			printf("\nTrocas = %d\n", trocas);
	}
	
	// Libera vetor
	free(vetor);

	return(0);
}
