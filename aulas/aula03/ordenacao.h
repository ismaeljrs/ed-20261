#ifndef ORDENACAO_H
#define ORDENACAO_H

void troca(int *a, int *b);
void imprimir_vetor(int v[], int n);
int particionar_vetor(int v[], int inicio, int fim);
void bubble_sort(int v[], int n);
void quick_sort(int v[], int inicio, int fim);

#endif