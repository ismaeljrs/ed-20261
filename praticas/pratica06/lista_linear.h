#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H

#include <stdbool.h>

// Definição do tipo opaco Lista (o ponteiro para a struct real)
typedef struct lista_t* Lista;

// Protótipos das funções exigidas no roteiro
Lista lista_criar();
bool lista_inserir(Lista lista, int valor);
bool lista_remover(Lista lista, int valor);
int lista_buscar(Lista lista, int valor); // Retorna a posição ou -1 se não achar
void lista_exibir(Lista lista);
bool lista_esta_vazia(Lista lista);
void lista_destruir(Lista lista);

#endif // LISTA_LINEAR_H