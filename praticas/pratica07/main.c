#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* minha_pilha = pilha_criar();
    int valor;

    printf("--- Prática 07: Estrutura de Dados - Pilha ---\n");

    printf("Empilhando elementos: 10, 20, 30\n");
    pilha_empilhar(minha_pilha, 10);
    pilha_empilhar(minha_pilha, 20);
    pilha_empilhar(minha_pilha, 30);
    pilha_exibir(minha_pilha);

    if (pilha_topo(minha_pilha, &valor)) {
        printf("Elemento no topo atual: %d\n", valor);
    }

    if (pilha_desempilhar(minha_pilha, &valor)) {
        printf("Desempilhado (elemento removido): %d\n", valor);
    }
    pilha_exibir(minha_pilha);

    printf("Destruindo a pilha...\n");
    pilha_destruir(minha_pilha);
    printf("Pilha liberada da memoria com sucesso.\n");

    return 0;
}