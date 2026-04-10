#include <stdio.h>
#include "ordenacao.h"

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_sort(int v[], int n) // O(n²)
{
    for (int i = 0; i < n - 1; i++) // n-1 vezes
    {
        for (int j = i + 1; j < n; j++) // n-1 vezes
        {
            if (v[i] > v[j])
            {
                troca(&v[i], &v[j]);
            }
        }
    }
}

void imprimir_vetor(int v[], int n)
{
    printf("[");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%i, ", v[i]);
    }
    printf("%i]\n", v[n - 1]);
}

int particionar_vetor(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;
    for(int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[fim]);
    return i + 1;
}

void quick_sort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar_vetor(v, inicio, fim);
        quick_sort(v, inicio, p - 1);
        quick_sort(v, p + 1, fim);
    }
}