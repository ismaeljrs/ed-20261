#include <stdio.h>
#include "fila.h"

int main() {
    Fila* minha_fila = fila_criar();
    int valor;

    printf("--- Prática 08: Estrutura de Dados - Fila Dinâmica ---\n");

    printf("Enfileirando elementos: 10, 20, 30\n");
    fila_enfileirar(minha_fila, 10);
    fila_enfileirar(minha_fila, 20);
    fila_enfileirar(minha_fila, 30);
    lista_exibir(minha_fila);

    if (fila_inicio(minha_fila, &valor)) {
        printf("Primeiro elemento da fila (inicio): %d\n", valor);
    }

    if (fila_desenfileirar(minha_fila, &valor)) {
        printf("Desenfileirado (elemento removido): %d\n", valor);
    }
    lista_exibir(minha_fila);

    printf("Destruindo a fila...\n");
    fila_destruir(minha_fila);
    printf("Fila liberada da memoria com sucesso.\n");

    return 0;
}