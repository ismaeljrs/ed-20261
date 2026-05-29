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

    tabela->dados = (int *)malloc(sizeof(int)*tamanho);
    memset(tabela->dados, 0, sizeof(int)*tamanho);
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

    tabela_hash->dados[hash] = valor;
    tabela_hash->quantidade++;
}

int buscar(TabelaHash *tabela_hash, int valor) {
    int hash = calcular_hash(valor);

    if (tabela_hash->dados[hash] == valor) {
        return hash;
    }

    return -1;
}

void remover(TabelaHash *tabela_hash, int valor) {
    int achei = buscar(tabela_hash, valor);
    
    if (achei < 0) {
        return;
    }

    tabela_hash->dados[achei] = 0;
    tabela_hash->quantidade--;
}

int tabela_vazia(TabelaHash *tabela_hash) {
    return tabela_hash != NULL 
        && tabela_hash->quantidade == 0;
}