#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

// Struct interna para o Nó (Contém valor, anterior e proximo)
typedef struct no_t {
    int valor;
    struct no_t* anterior;
    struct no_t* proximo;
} no_t;

// Struct interna para a Lista (Contém ponteiros para o primeiro e ultimo)
struct lista_t {
    no_t* primeiro;
    no_t* ultimo;
};

// Cria uma lista vazia
Lista lista_criar() {
    Lista nova = (Lista)malloc(sizeof(struct lista_t));
    if (nova != NULL) {
        nova->primeiro = NULL;
        nova->ultimo = NULL;
    }
    return nova;
}

// Verifica se está vazia
bool lista_esta_vazia(Lista lista) {
    if (lista == NULL) return true;
    return (lista->primeiro == NULL);
}

// Insere no final da lista
bool lista_inserir(Lista lista, int valor) {
    if (lista == NULL) return false;
    
    no_t* novo_no = (no_t*)malloc(sizeof(no_t));
    if (novo_no == NULL) return false;
    
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    
    if (lista_esta_vazia(lista)) {
        novo_no->anterior = NULL;
        lista->primeiro = novo_no;
        lista->ultimo = novo_no;
    } else {
        novo_no->anterior = lista->ultimo;
        lista->ultimo->proximo = novo_no;
        lista->ultimo = novo_no;
    }
    return true;
}

// Remove um elemento por valor
bool lista_remover(Lista lista, int valor) {
    if (lista == NULL || lista_esta_vazia(lista)) return false;
    
    no_t* atual = lista->primeiro;
    
    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }
    
    if (atual == NULL) return false; // Não achou
    
    if (atual == lista->primeiro) { // Remove o primeiro
        lista->primeiro = atual->proximo;
        if (lista->primeiro != NULL) {
            lista->primeiro->anterior = NULL;
        } else {
            lista->ultimo = NULL; // Lista ficou vazia
        }
    } else if (atual == lista->ultimo) { // Remove o último
        lista->ultimo = atual->anterior;
        lista->ultimo->proximo = NULL;
    } else { // Remove do meio
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
    }
    
    free(atual);
    return true;
}

// Busca o elemento e retorna o índice (posição) dele
int lista_buscar(Lista lista, int valor) {
    if (lista == NULL || lista_esta_vazia(lista)) return -1;
    
    no_t* atual = lista->primeiro;
    int indice = 0;
    
    while (atual != NULL) {
        if (atual->valor == valor) {
            return indice;
        }
        atual = atual->proximo;
        indice++;
    }
    return -1;
}

// Exibe todos os elementos da lista da esquerda para a direita
void lista_exibir(Lista lista) {
    if (lista == NULL || lista_esta_vazia(lista)) {
        printf("Lista vazia.\n");
        return;
    }
    
    no_t* atual = lista->primeiro;
    printf("Lista: [ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}

// Libera toda a memória da lista
void lista_destruir(Lista lista) {
    if (lista == NULL) return;
    
    no_t* atual = lista->primeiro;
    while (atual != NULL) {
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(lista);
}