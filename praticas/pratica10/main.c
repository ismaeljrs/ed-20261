#include <stdio.h>
#include "tabela_hash.h"

int main() {
    
    TabelaHash* minha_hash = hash_criar(7);

    printf("--- Prática 10: Tabela Hash com Encadeamento ---\n");

    
    printf("Inserindo elementos: 10, 20, 17, 24, 31, 5\n");
    hash_inserir(minha_hash, 10); 
    hash_inserir(minha_hash, 20); 
    hash_inserir(minha_hash, 17); 
    hash_inserir(minha_hash, 24); 
    hash_inserir(minha_hash, 31); 
    hash_inserir(minha_hash, 5);  


    hash_exibir(minha_hash);

    
    int busca = 17;
    if (hash_buscar(minha_hash, busca)) {
        printf("Elemento %d encontrado na tabela!\n", busca);
    } else {
        printf("Elemento %d NAO encontrado.\n", busca);
    }


    printf("\nRemovendo o elemento 17...\n");
    hash_remover(minha_hash, 17);
    
   
    hash_exibir(minha_hash);

    
    printf("Destruindo a tabela hash...\n");
    hash_destruir(minha_hash);
    printf("Memoria liberada com sucesso!\n");

    return 0;
}