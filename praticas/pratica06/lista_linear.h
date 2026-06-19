#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H

#define TRUE 1
#define FALSE 0

typedef struct lista_t Lista;

Lista* lista_criar();
int lista_inserir(Lista* l, int valor);
int lista_remover(Lista* l, int valor);
int lista_buscar(Lista* l, int valor);
void lista_exibir(Lista* l);
int lista_esta_vazia(Lista* l);
void lista_destruir(Lista* l);