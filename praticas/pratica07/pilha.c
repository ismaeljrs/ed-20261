#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

struct pilha_t {
    no_t* topo;
};

Pilha* pilha_criar() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = NULL;
    }
    return p;
}

int pilha_esta_vazia(Pilha* p) {
    if (p == NULL || p->topo == NULL) {
        return TRUE;
    }
    return FALSE;
}

int pilha_empilhar(Pilha* p, int valor) {
    if (p == NULL) return FALSE;

    no_t* novo = (no_t*)malloc(sizeof(no_t));
    if (novo == NULL) return FALSE;

    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;

    return TRUE;
}

int pilha_desempilhar(Pilha* p, int* valor_removido) {
    if (pilha_esta_vazia(p)) return FALSE;

    no_t* aux = p->topo;
    if (valor_removido != NULL) {
        *valor_removido = aux->valor;
    }
    p->topo = aux->proximo;
    free(aux);

    return TRUE;
}

int pilha_topo(Pilha* p, int* valor_topo) {
    if (pilha_esta_vazia(p)) return FALSE;
    if (valor_topo != NULL) {
        *valor_topo = p->topo->valor;
    }
    return TRUE;
}

void pilha_exibir(Pilha* p) {
    if (pilha_esta_vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    no_t* atual = p->topo;
    printf("Pilha (Topo -> Base): ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void pilha_destruir(Pilha* p) {
    if (p != NULL) {
        while (!pilha_esta_vazia(p)) {
            pilha_desempilhar(p, NULL);
        }
        free(p);
    }
}