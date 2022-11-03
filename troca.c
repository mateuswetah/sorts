/* Operação de troca generica, usada por varios algoritmos */
void troca(int *x, int* y) {
	int aux;
	aux = *x;
	*x = *y;
	*y = aux;
}