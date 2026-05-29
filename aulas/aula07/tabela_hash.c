#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

int calcular_hash(int valor)
{
    return valor / 3;
}

TabelaHash *criar(int tamanho)
{
    TabelaHash *tabela = 
        (TabelaHash *)malloc(sizeof(TabelaHash));

    if (tabela == NULL) {
        return NULL;
    }

    tabela->dados = (No **)malloc(sizeof(No*)*tamanho);
    memset(tabela->dados, 0, sizeof(No*)*tamanho);
    tabela->quantidade = 0;
    tabela->tamanho = tamanho;

    return tabela;
}

void destruir(TabelaHash *tabela_hash) {
    free(tabela_hash->dados);
    free(tabela_hash);
}

void inserir(TabelaHash *tabela_hash, int valor) {
    int hash = calcular_hash(valor);

    No *no = (No *)malloc(sizeof(No));
    no->dado = valor;
    no->proximo = tabela_hash->dados[hash];
    tabela_hash->dados[hash] = no;
    tabela_hash->quantidade++;
}

int buscar(TabelaHash *tabela_hash, int valor) {
    int hash = calcular_hash(valor);

    No *no = tabela_hash->dados[hash];
    while(no != NULL) {
        if (no->dado == valor) {
            return hash;
        }
        no = no->proximo;
    }

    return -1;
}

void remover(TabelaHash *tabela_hash, int valor) {
    int achei = buscar(tabela_hash, valor);
    
    if (achei < 0) {
        return;
    }

    No *no = tabela_hash->dados[achei];
    if (no->dado == valor) {
       tabela_hash->dados[achei] = no->proximo;
       tabela_hash->quantidade--;
       return;
    }

    while (no->proximo != NULL) {
        No *anterior = no;
        no = no->proximo;
        if(no->dado == valor) {
            anterior = no->proximo;           
            return;
        }
    }
    tabela_hash->quantidade--;
}

int tabela_vazia(TabelaHash *tabela_hash) {
    return tabela_hash != NULL 
        && tabela_hash->quantidade == 0;
}