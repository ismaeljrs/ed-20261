#ifndef ARVORE_BST_H
#define ARVORE_BST_H

typedef struct No {
    int *dado;
    struct No **filhos;
//    struct No *esquerda;
    //struct No *direita;
} No;

No *criar(int valor);
void destruir(No* no);
No *inserir(No *no, int valor);
No *buscar(No *no, int valor);
void pre_ordem(No *no);
void em_ordem(No *no);
void pos_ordem(No *no);

#endif