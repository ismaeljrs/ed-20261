#ifndef TABELA_HASH_H
#define TABELA_HASH_H

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct {
    No **dados; // array de ponteiros
    int quantidade;
    int tamanho;
} TabelaHash;

TabelaHash *criar(int tamanho);
void destruir(TabelaHash *tabela_hash);
void inserir(TabelaHash *tabela_hash, int valor);
int buscar(TabelaHash *tabela_hash, int valor);
void remover(TabelaHash *tabela_hash, int valor);
int tabela_vazia(TabelaHash *tabela_hash);

#endif