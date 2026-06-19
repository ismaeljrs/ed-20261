#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t {
    int valor;
    struct no_t* anterior;
    struct no_t* proximo;
} no_t;

struct lista_t {
    no_t* primeiro;
    no_t* ultimo;
};

Lista* lista_criar() {
    Lista* l = (Lista*)malloc(sizeof(Lista));
    if (l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

int lista_esta_vazia(Lista* l) {
    if (l == NULL || l->primeiro == NULL) return TRUE;
    return FALSE;
}

int lista_inserir(Lista* l, int valor) {
    if (l == NULL) return FALSE;
    no_t* novo = (no_t*)malloc(sizeof(no_t));
    if (novo == NULL) return FALSE;

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = l->ultimo;

    if (lista_esta_vazia(l)) {
        l->primeiro = novo;
    } else {
        l->ultimo->proximo = novo;
    }
    l->ultimo = novo;
    return TRUE;
}

int lista_buscar(Lista* l, int valor) {
    if (lista_esta_vazia(l)) return FALSE;
    no_t* atual = l->primeiro;
    while (atual != NULL) {
        if (atual->valor == valor) return TRUE;
        atual = atual->proximo;
    }
    return FALSE;
}

int lista_remover(Lista* l, int valor) {
    if (lista_esta_vazia(l)) return FALSE;
    no_t* atual = l->primeiro;

    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }

    if (atual == NULL) return FALSE; // Não achou

    if (atual == l->primeiro) {
        l->primeiro = atual->proximo;
        if (l->primeiro != NULL) l->primeiro->anterior = NULL;
    } else {
        atual->anterior->proximo = atual->proximo;
    }

    if (atual == l->ultimo) {
        l->ultimo = atual->anterior;
        if (l->ultimo != NULL) l->ultimo->proximo = NULL;
    } else {
        if (atual->proximo != NULL) atual->proximo->anterior = atual->anterior;
    }

    free(atual);
    return TRUE;
}

void lista_exibir(Lista* l) {
    if (lista_esta_vazia(l)) {
        printf("Lista vazia.\n");
        return;
    }
    no_t* atual = l->primeiro;
    printf("Lista: ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void lista_destruir(Lista* l) {
    if (l != NULL) {
        no_t* atual = l->primeiro;
        while (atual != NULL) {
            no_t* aux = atual->proximo;
            free(atual);
            atual = aux;
        }
        free(l);
    }
}