#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

struct hash_t {
    no_t** tabela;
    int tamanho;
};

// Função Hash interna (Divisão)
int funcao_hash(int valor, int tamanho) {
    int pos = valor % tamanho;
    if (pos < 0) pos += tamanho; // Trata números negativos
    return pos;
}

TabelaHash* hash_criar(int tamanho) {
    if (tamanho <= 0) return NULL;
    
    TabelaHash* h = (TabelaHash*)malloc(sizeof(TabelaHash));
    if (h != NULL) {
        h->tamanho = tamanho;
        h->tabela = (no_t**)malloc(tamanho * sizeof(no_t*));
        if (h->tabela == NULL) {
            free(h);
            return NULL;
        }
        for (int i = 0; i < tamanho; i++) {
            h->tabela[i] = NULL;
        }
    }
    return h;
}

int hash_esta_vazia(TabelaHash* h) {
    if (h == NULL || h->tabela == NULL) return TRUE;
    for (int i = 0; i < h->tamanho; i++) {
        if (h->tabela[i] != NULL) return FALSE;
    }
    return TRUE;
}

int hash_inserir(TabelaHash* h, int valor) {
    if (h == NULL) return FALSE;
    
    // Evita duplicatas para simplificar a busca/remoção
    if (hash_buscar(h, valor)) return FALSE;

    int pos = funcao_hash(valor, h->tamanho);
    
    no_t* novo = (no_t*)malloc(sizeof(no_t));
    if (novo == NULL) return FALSE;
    
    novo->valor = valor;
    // Insere no início da lista encadeada daquela posição (Tratamento de Colisão)
    novo->proximo = h->tabela[pos];
    h->tabela[pos] = novo;
    
    return TRUE;
}

int hash_buscar(TabelaHash* h, int valor) {
    if (h == NULL || h->tabela == NULL) return FALSE;
    
    int pos = funcao_hash(valor, h->tamanho);
    no_t* atual = h->tabela[pos];
    
    while (atual != NULL) {
        if (atual->valor == valor) {
            return TRUE;
        }
        atual = atual->proximo;
    }
    return FALSE;
}

int hash_remover(TabelaHash* h, int valor) {
    if (h == NULL || h->tabela == NULL) return FALSE;
    
    int pos = funcao_hash(valor, h->tamanho);
    no_t* atual = h->tabela[pos];
    no_t* anterior = NULL;
    
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual == NULL) return FALSE; // Não achou
    
    if (anterior == NULL) {
        h->tabela[pos] = atual->proximo; // Era o primeiro item
    } else {
        anterior->proximo = atual->proximo; // Estava no meio ou fim
    }
    
    free(atual);
    return TRUE;
}

void hash_exibir(TabelaHash* h) {
    if (h == NULL || h->tabela == NULL) {
        printf("Tabela Hash inexistente.\n");
        return;
    }
    
    printf("\n--- Estrutura da Tabela Hash ---\n");
    for (int i = 0; i < h->tamanho; i++) {
        printf("[%d]: ", i);
        no_t* atual = h->tabela[i];
        if (atual == NULL) {
            printf("NULL");
        }
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
            if (atual == NULL) printf("NULL");
        }
        printf("\n");
    }
    printf("--------------------------------\n");
}

void hash_destruir(TabelaHash* h) {
    if (h != NULL) {
        if (h->tabela != NULL) {
            for (int i = 0; i < h->tamanho; i++) {
                no_t* atual = h->tabela[i];
                while (atual != NULL) {
                    no_t* aux = atual->proximo;
                    free(atual);
                    atual = aux;
                }
            }
            free(h->tabela);
        }
        free(h);
    }
}