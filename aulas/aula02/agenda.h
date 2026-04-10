#ifndef AGENDA_H
#define AGENDA_H

#define LIMITE 100

typedef struct contato_t {
    char nome[101];
    char telefone[21];
} Contato;

typedef struct agenda_t {
    Contato contatos[LIMITE];
    int tamanho;
    int quantidade;
} Agenda;

Agenda criar_agenda(int tamanho);
void adicionar_contato(Agenda *agenda, Contato contato);
void remover_contato(Agenda *agenda, Contato contato);
void bloquear_contato(Agenda *agenda, Contato contato);
void desbloquear_contato(Agenda *agenda, Contato contato);
void editar_contato(Agenda *agenda, Contato contato);
void listar_contato(Agenda *agenda);

#endif