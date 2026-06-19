#include <stdio.h>
#include "lista_linear.h"

int main() {
    printf("--- Testando Lista Linear Dinâmica ---\n\n");
    
    Lista minha_lista = lista_criar();
    
    // 1. Inserindo dados
    printf("Inserindo 10, 20, 30, 40...\n");
    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 20);
    lista_inserir(minha_lista, 30);
    lista_inserir(minha_lista, 40);
    lista_exibir(minha_lista);
    
    // 2. Buscando dados
    int pos = lista_buscar(minha_lista, 30);
    printf("\nBuscando o valor 30... Encontrado na posicao: %d\n", pos);
    
    pos = lista_buscar(minha_lista, 99);
    printf("Buscando o valor 99... Resposta: %d (nao existe)\n", pos);
    
    // 3. Removendo dados
    printf("\nRemovendo o valor 20 do meio da lista...\n");
    lista_remover(minha_lista, 20);
    lista_exibir(minha_lista);
    
    printf("\nRemovendo o valor 10 (o primeiro da lista)...\n");
    lista_remover(minha_lista, 10);
    lista_exibir(minha_lista);

    // 4. Destruindo a lista
    printf("\nLimpando memoria e encerrando...\n");
    lista_destruir(minha_lista);
    
    printf("Pratica 06 executada com sucesso!\n");
    return 0;
}