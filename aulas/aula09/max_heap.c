#include <stdlib.h>
#include "max_heap.h"

MaxHeap *criar(int capacidade)
{
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));

    if (heap == NULL)
    {
        return NULL;
    }

    heap->dados = (int *)malloc(sizeof(int) * capacidade);
    heap->capacidade = capacidade;
    heap->tamanho = 0;
    return heap;
}

void destruir(MaxHeap *raiz)
{
    free(raiz->dados);
    free(raiz);
}

// algoritmo de flutuação
void up_heap(MaxHeap *raiz, int indice)
{
    int indice_pai = (indice - 1) / 2;

    while (indice > 0 && raiz->dados[indice] > raiz->dados[indice_pai])
    {
        // troca filho com pai
        int temp = raiz->dados[indice];
        raiz->dados[indice] = raiz->dados[indice_pai];
        raiz->dados[indice_pai] = temp;

        // sobe um nivel da heap
        indice = indice_pai;
        indice_pai = (indice - 1) / 2;
    }
}

void inserir(MaxHeap *raiz, int valor)
{
    if (raiz->tamanho >= raiz->capacidade)
    {
        return;
    }

    raiz->dados[raiz->tamanho] = valor;
    raiz->tamanho++;
    up_heap(raiz, raiz->tamanho - 1);
}

// algortimo afundamento
void down_heap(MaxHeap *raiz, int indice)
{
    int maior = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    if (esquerda < raiz->tamanho && raiz->dados[esquerda] > raiz->dados[maior])
    {
        maior = esquerda;
    }

    if (direita < raiz->tamanho && raiz->dados[direita] > raiz->dados[maior])
    {
        maior = direita;
    }

    if (maior != indice) {
        int temp = raiz->dados[indice];
        raiz->dados[indice] = raiz->dados[maior];
        raiz->dados[maior] = temp;

        down_heap(raiz, maior);
    }
}

int remover(MaxHeap *raiz)
{
    if (raiz->tamanho == 0)
    {
        return -1;
    }

    int valor = raiz->dados[0];
    raiz->dados[0] = raiz->dados[raiz->tamanho - 1];
    raiz->tamanho--;

    down_heap(raiz, 0);
    return valor;
}