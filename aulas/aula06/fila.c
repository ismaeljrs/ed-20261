#include <stdlib.h>
#include "fila.h"

Fila *criar() {
    Fila *fila = (Fila *)malloc(sizeof(Fila));

    if (fila == NULL) 
        return NULL;
    
    fila->primeiro = NULL;  
    fila->ultimo = NULL;
    fila->quantidade = 0;
    return fila;
}

void destruir(Fila *fila) {
    free(fila);
}

void enfileirar(Fila *fila, int valor) {
    No *no = (No *)malloc(sizeof(No));
    no->dados = valor;
    no->proximo = NULL;

    if (fila_vazia(fila)) {
        fila->primeiro = no;
        fila->ultimo = no;
        fila->quantidade++;
        return;
    }

    fila->ultimo->proximo = no;
    fila->ultimo = no;
    fila->quantidade++;
}

void desenfileirar(Fila *fila) {
    if (fila_vazia(fila))
        return;

    No *no = fila->primeiro;
    fila->primeiro = no->proximo;
    fila->quantidade--;

    if (fila_vazia(fila)) {
        fila->ultimo = NULL;
    }
    
    free(no);
}

int fila_vazia(Fila *fila) {
   return fila != NULL && fila->primeiro == NULL;
}