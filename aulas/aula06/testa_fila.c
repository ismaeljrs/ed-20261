#include <stdio.h>
#include "fila.h"

int main() {
    Fila *f = criar();

    enfileirar(f, 1);
    enfileirar(f, 8);
    enfileirar(f, 0);

    No *no = f->primeiro;
    while(no != NULL) {
        printf("%i -> ", no->dados);
        no = no->proximo;
    }
    printf("\n");

    desenfileirar(f);

    no = f->primeiro;
    while(no != NULL) {
        printf("%i -> ", no->dados);
        no = no->proximo;
    }
    printf("\n");

    enfileirar(f, 6);

    no = f->primeiro;
    while(no != NULL) {
        printf("%i -> ", no->dados);
        no = no->proximo;
    }    
    printf("\n");

    desenfileirar(f);

    no = f->primeiro;
    while(no != NULL) {
        printf("%i -> ", no->dados);
        no = no->proximo;
    }    
    printf("\n");

    desenfileirar(f);

    no = f->primeiro;
    while(no != NULL) {
        printf("%i -> ", no->dados);
        no = no->proximo;
    }
    printf("\n");
    
    return 0;
}