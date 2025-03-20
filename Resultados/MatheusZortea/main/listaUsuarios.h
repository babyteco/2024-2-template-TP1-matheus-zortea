#ifndef _LISTAUSUARIOS_H
#define _LISTAUSUARIOS_H

#include "usuario.h"
#include "data.h"
#include "ticket.h"


typedef struct ListaUsuarios ListaUsuarios;


ListaUsuarios *criaListaUsuarios();

void insereUsuarioLista(ListaUsuarios *lu, Usuario *u);

void desalocaListaUsuarios(ListaUsuarios *lu);

int getQtdUsuariosCadastrados(ListaUsuarios *lu);

Usuario *getUsuarioNaLista(ListaUsuarios *lu, int i);

int comparaCPF(ListaUsuarios *lu, char *cpf);

void TrocaPosicaoUsuarios(ListaUsuarios *lu, int i);

ListaUsuarios *CopiaListaUsuarios(ListaUsuarios *lu);

void RankingUsuario(ListaUsuarios *lu);

void notificaListaUsuarios(ListaUsuarios *lu);

void notificaRankingUsuarios(ListaUsuarios *lu);

int MediaIdadeUsuarios(ListaUsuarios *lu);

#endif