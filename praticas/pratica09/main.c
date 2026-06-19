#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    Arvore* minha_arvore = arvore_criar();

    printf("--- Prática 09: Estrutura de Dados - Árvore Binária ---\n");

    // Inserindo elementos na árvore
    printf("Inserindo elementos: 50, 30, 70, 20, 40, 60, 80\n\n");
    arvore_inserir(minha_arvore, 50);
    arvore_inserir(minha_arvore, 30);
    arvore_inserir(minha_arvore, 70);
    arvore_inserir(minha_arvore, 20);
    arvore_inserir(minha_arvore, 40);
    arvore_inserir(minha_arvore, 60);
    arvore_inserir(minha_arvore, 80);

    // Exibindo nos 3 percursos
    arvore_exibir_pre_ordem(minha_arvore);
    arvore_exibir_em_ordem(minha_arvore);
    arvore_exibir_pos_ordem(minha_arvore);

    // Liberando memória
    printf("\nDestruindo a árvore...\n");
    arvore_destruir(minha_arvore);
    printf("Árvore liberada da memória com sucesso.\n");

    return 0;
}