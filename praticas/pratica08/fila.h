#ifndef FILA_H
#define FILA_H

#define TRUE 1
#define FALSE 0

typedef struct fila_t Fila;

Fila* fila_criar();
int fila_enfileirar(Fila* f, int valor);
int fila_desenfileirar(Fila* f, int* valor_removido);
int fila_inicio(Fila* f, int* valor_inicio);
int fila_esta_vazia(Fila* f);
void lista_exibir(Fila* f); // Nome exigido pelo roteiro
void fila_destruir(Fila* f);

#endif