#ifndef _LISTAUSUARIOS_H
#define _LISTAUSUARIOS_H

#include "usuario.h"
#include "data.h"
#include "ticket.h"


typedef struct ListaUsuarios ListaUsuarios;


ListaUsuarios *criaListaUsuarios();

void insereUsuarioLista(ListaUsuarios *lu, char *nome, char *cpf, char *telefone, char *genero, char *setor, Data d);

void desalocaListaUsuarios(ListaUsuarios *lu);

int getQtdUsuariosCadastrados(ListaUsuarios *lu);

Ticket *getUsuarioNaLista(ListaUsuarios *lu, int i);

void ContabilizaTicketUsuario(ListaUsuarios *lu, char* cpf);

void notificaListaUsuarios(ListaUsuarios *lu);

#endif