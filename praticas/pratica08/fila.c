#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

struct fila_t {
    no_t* inicio;
    no_t* fim;
};

Fila* fila_criar() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_esta_vazia(Fila* f) {
    if (f == NULL || f->inicio == NULL) {
        return TRUE;
    }
    return FALSE;
}

int fila_enfileirar(Fila* f, int valor) {
    if (f == NULL) return FALSE;

    no_t* novo = (no_t*)malloc(sizeof(no_t));
    if (novo == NULL) return FALSE;

    novo->valor = valor;
    novo->proximo = NULL;

    if (fila_esta_vazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->proximo = novo;
    }
    f->fim = novo;

    return TRUE;
}

int fila_desenfileirar(Fila* f, int* valor_removido) {
    if (fila_esta_vazia(f)) return FALSE;

    no_t* aux = f->inicio;
    if (valor_removido != NULL) {
        *valor_removido = aux->valor;
    }

    f->inicio = aux->proximo;
    if (f->inicio == NULL) {
        f->fim = NULL; // A fila ficou vazia
    }

    free(aux);
    return TRUE;
}

int fila_inicio(Fila* f, int* valor_inicio) {
    if (fila_esta_vazia(f)) return FALSE;
    if (valor_inicio != NULL) {
        *valor_inicio = f->inicio->valor;
    }
    return TRUE;
}

void lista_exibir(Fila* f) {
    if (fila_esta_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    no_t* atual = f->inicio;
    printf("Fila (Inicio -> Fim): ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void fila_destruir(Fila* f) {
    if (f != NULL) {
        while (!fila_esta_vazia(f)) {
            fila_desenfileirar(f, NULL);
        }
        free(f);
    }
}