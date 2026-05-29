#ifndef PILHA_H
#define PILHA_H

typedef struct No {
    int dados;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
    int quantidade;
} Pilha;

Pilha *criar();
int pilha_vazia(Pilha *pilha);
No *pilha_topo(Pilha *pilha);
void empilhar(Pilha *pilha, int valor);
void desempilhar(Pilha *pilha);
void destruir(Pilha *pilha);

#endif 