#ifndef MAX_HEAP_H
#define MAX_HEAP_H

typedef struct {
    int *dados;
    int capacidade;
    int tamanho;
} MaxHeap;

MaxHeap *criar(int capacidade);
void destruir(MaxHeap *raiz);
void inserir(MaxHeap *raiz, int valor);
int remover(MaxHeap *raiz);

#endif