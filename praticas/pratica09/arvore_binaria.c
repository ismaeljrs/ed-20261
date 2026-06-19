#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t {
    struct no_t* esquerda;
    int valor;
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
    if (a == NULL || a->raiz == NULL) {
        return TRUE;
    }
    return FALSE;
}

// Função auxiliar recursiva para inserir no nó correto
no_t* inserir_no(no_t* no, int valor, int* sucesso) {
    if (no == NULL) {
        no_t* novo = (no_t*)malloc(sizeof(no_t));
        if (novo != NULL) {
            novo->valor = valor;
            novo->esquerda = NULL;
            novo->direita = NULL;
            *sucesso = TRUE;
            return novo;
        }
        *sucesso = FALSE;
        return NULL;
    }

    if (valor < no->valor) {
        no->esquerda = inserir_no(no->esquerda, valor, sucesso);
    } else if (valor > no->valor) {
        no->direita = inserir_no(no->direita, valor, sucesso);
    } else {
        *sucesso = FALSE; // Valores duplicados não entram na árvore de busca
    }

    return no;
}

int arvore_inserir(Arvore* a, int valor) {
    if (a == NULL) return FALSE;
    int sucesso = FALSE;
    a->raiz = inserir_no(a->raiz, valor, &sucesso);
    return sucesso;
}

// Funções auxiliares para percursos (Exibição)
void pre_ordem(no_t* no) {
    if (no != NULL) {
        printf("%d ", no->valor);
        pre_ordem(no->esquerda);
        pre_ordem(no->direita);
    }
}

void em_ordem(no_t* no) {
    if (no != NULL) {
        em_ordem(no->esquerda);
        printf("%d ", no->valor);
        em_ordem(no->direita);
    }
}

void pos_ordem(no_t* no) {
    if (no != NULL) {
        pos_ordem(no->esquerda);
        pos_ordem(no->direita);
        printf("%d ", no->valor);
    }
}

void arvore_exibir_pre_ordem(Arvore* a) {
    if (arvore_esta_vazia(a)) {
        printf("Arvore vazia.\n");
        return;
    }
    printf("Pré-Ordem: ");
    pre_ordem(a->raiz);
    printf("\n");
}

void arvore_exibir_em_ordem(Arvore* a) {
    if (arvore_esta_vazia(a)) {
        printf("Arvore vazia.\n");
        return;
    }
    printf("Em-Ordem: ");
    em_ordem(a->raiz);
    printf("\n");
}

void arvore_exibir_pos_ordem(Arvore* a) {
    if (arvore_esta_vazia(a)) {
        printf("Arvore vazia.\n");
        return;
    }
    printf("Pós-Ordem: ");
    pos_ordem(a->raiz);
    printf("\n");
}

// Função auxiliar para destruir nós recursivamente
void destruir_nos(no_t* no) {
    if (no != NULL) {
        destruir_nos(no->esquerda);
        destruir_nos(no->direita);
        free(no);
    }
}

void arvore_destruir(Arvore* a) {
    if (a != NULL) {
        destruir_nos(a->raiz);
        free(a);
    }
}