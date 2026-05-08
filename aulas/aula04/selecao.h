#ifndef SELECAO_H
#define SELECAO_H

int busca_sequencial(int v[], int n, int valor);

void troca(int *a, int *b);
int particionar_vetor(int v[], int inicio, int fim);
int quick_select(int v[], int inicio, int fim, int valor);

#endif