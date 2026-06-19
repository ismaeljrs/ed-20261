#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#define TRUE 1
#define FALSE 0

typedef struct hash_t TabelaHash;

TabelaHash* hash_criar(int tamanho);
int hash_inserir(TabelaHash* h, int valor);
int hash_buscar(TabelaHash* h, int valor);
int hash_remover(TabelaHash* h, int valor);
void hash_exibir(TabelaHash* h);
int hash_esta_vazia(TabelaHash* h);
void hash_destruir(TabelaHash* h);

#endif