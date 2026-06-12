#include <stdio.h>
#include "max_heap.h"

void heap_imprimir(MaxHeap *raiz) {
    printf("Fila de Prioridade (Max Heap): ");
    for (int i = 0; i < raiz->tamanho; i++) {
        printf("%d ", raiz->dados[i]);
    }
    printf("\n");
}

int main() {
    MaxHeap *fila_prioridade = criar(100);

    printf("--- FASE DE INSERÇÃO ---\n");
    inserir(fila_prioridade, 34);
    heap_imprimir(fila_prioridade);
    
    inserir(fila_prioridade, 12);
    heap_imprimir(fila_prioridade);
    
    inserir(fila_prioridade, 90); // Deve flutuar para a raiz
    printf("Inserindo 90 (Maior Prioridade):\n");
    heap_imprimir(fila_prioridade);
    
    inserir(fila_prioridade, 64);
    inserir(fila_prioridade, 22);
    heap_imprimir(fila_prioridade);

    printf("Repriorizando elemento no índice 2:\n");
    repriorizar(fila_prioridade, 2, 95); // Aumenta a prioridade do elemento no índice 2
    heap_imprimir(fila_prioridade);

    printf("\n--- FASE DE EXTRAÇÃO ---\n");
    int valor_removido = remover(fila_prioridade); 
    printf("Atendido/Removido: %d\n", valor_removido);
    heap_imprimir(fila_prioridade);

    valor_removido = remover(fila_prioridade);
    printf("Atendido/Removido: %d\n", valor_removido);
    heap_imprimir(fila_prioridade);

    return 0;
}