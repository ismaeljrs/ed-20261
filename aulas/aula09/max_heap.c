#include <stdlib.h>
#include "max_heap.h"

MaxHeap *criar(int capacidade) {
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->dados = (int *)malloc(capacidade * sizeof(int));
    heap->capacidade = capacidade;
    heap->tamanho = 0;
    return heap;
}

void destruir(MaxHeap *raiz) {
    free(raiz->dados);
    free(raiz);
}

void up_heap(MaxHeap *raiz, int indice) {
    int indice_pai = (indice - 1) / 2;

    while (indice > 0 && raiz->dados[indice] > raiz->dados[indice_pai]) {
        int temp = raiz->dados[indice];
        raiz->dados[indice] = raiz->dados[indice_pai];
        raiz->dados[indice_pai] = temp;

        indice = indice_pai;
        indice_pai = (indice - 1) / 2;
    }
}

void down_heap(MaxHeap *raiz, int indice) {
    int maior = indice;
    int esq = 2 * indice + 1;
    int dir = 2 * indice + 2;

    if (esq < raiz->tamanho && raiz->dados[esq] > raiz->dados[maior]) {
        maior = esq;
    }

    if (dir < raiz->tamanho && raiz->dados[dir] > raiz->dados[maior]) {
        maior = dir;
    }

    if (maior != indice) {
        int temp = raiz->dados[indice];
        raiz->dados[indice] = raiz->dados[maior];
        raiz->dados[maior] = temp;

        down_heap(raiz, maior);
    }
}

void inserir(MaxHeap *raiz, int valor) {
    if (raiz->tamanho >= raiz->capacidade) {
        return;
    }

    raiz->dados[raiz->tamanho] = valor;
    raiz->tamanho++;
    up_heap(raiz, raiz->tamanho - 1);
}

int remover(MaxHeap *raiz) {
    if (raiz->tamanho <= 0) {
        return 0; // Heap Vazia
    }

    int valor = raiz->dados[0];
    raiz->dados[0] = raiz->dados[raiz->tamanho - 1];
    raiz->tamanho--;

    down_heap(raiz, 0);
    return valor;
}

void repriorizar(MaxHeap *raiz, int indice, int nova_prioridade) {
    if (indice < 0 || indice >= raiz->tamanho) {
        return;
    }
   
    int antiga_prioridade = raiz->dados[indice];
    raiz->dados[indice] = nova_prioridade;

    if (nova_prioridade > antiga_prioridade) {
        up_heap(raiz, indice);
    } else {
        down_heap(raiz, indice);
    }
}