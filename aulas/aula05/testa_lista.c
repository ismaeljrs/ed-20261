#include <stdio.h>
#include "lista_encadeada.h"

int main() {
    ListaEncadeada *lista = criar();

    adicionar_final(lista, 50);
    adicionar_final(lista, 25);
    adicionar_final(lista, 10);
    adicionar_final(lista, 60);
    adicionar_final(lista, 5);
    adicionar_final(lista, 41);
    adicionar_final(lista, 9);

    printf("A lista em %i nos => ", lista->quantidade);
    No *no = lista->primeiro;
    while (no != NULL) {
        printf("%i ", no->dado);
        no = no->proximo;
    }
    printf("\n");

    no = buscar(lista, 60);
    printf("O valor 60 esta no No %p\n", no);
    no = buscar(lista, 65);
    printf("O valor 65 esta no No %p\n", no);


    remover(lista, 50);
    remover(lista, 10);
    remover(lista, 9);

    printf("A lista em %i nos => ", lista->quantidade);
    no = lista->primeiro;
    while (no != NULL) {
        printf("%i ", no->dado);
        no = no->proximo;
    }
    printf("\n");

    return 0;
}