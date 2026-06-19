#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t {
    int valor;
    struct no_t* esquerda;
    struct no_t* direita;
} no_t;

struct arvore_t {
    no_t* raiz;
};

Arvore* arvore_criar() {
    Arvore* a = (Arvore*)malloc(sizeof(Arvore));
    if (a != NULL) {
        a->raiz = NULL;
    }
    return a;
}

int arvore_esta_vazia(Arvore* a) {
    if (a == NULL || a->raiz == NULL) return TRUE;
    return FALSE;
}

no_t* inserir_no(no_t* raiz, int valor, int* inserido) {
    if (raiz == NULL) {
        no_t* novo = (no_t*)malloc(sizeof(no_t));
        if (novo != NULL) {
            novo->valor = valor;
            novo->esquerda = NULL;
            novo->direita = NULL;
            *inserido = TRUE;
            return novo;
        }
        return NULL;
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir_no(raiz->esquerda, valor, inserido);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_no(raiz->direita, valor, inserido);
    }
    return raiz;
}

int arvore_inserir(Arvore* a, int valor) {
    if (a == NULL) return FALSE;
    int inserido = FALSE;
    a->raiz = inserir_no(a->raiz, valor, &inserido);
    return inserido;
}

void pre_ordem(no_t* n) {
    if (n == NULL) return;
    printf("[%d] ", n->valor);
    pre_ordem(n->esquerda);
    pre_ordem(n->direita);
}

void arvore_exibir_pre_ordem(Arvore* a) {
    if (arvore_esta_vazia(a)) return;
    pre_ordem(a->raiz);
    printf("\n");
}

void em_ordem(no_t* n) {
    if (n == NULL) return;
    em_ordem(n->esquerda);
    printf("[%d] ", n->valor);
    em_ordem(n->direita);
}

void arvore_exibir_em_ordem(Arvore* a) {
    if (arvore_esta_vazia(a)) return;
    em_ordem(a->raiz);
    printf("\n");
}

void destruir_no(no_t* n) {
    if (n == NULL) return;
    destruir_no(n->esquerda);
    destruir_no(n->direita);
    free(n);
}

void arvore_destruir(Arvore* a) {
    if (a != NULL) {
        destruir_no(a->raiz);
        free(a);
    }
}