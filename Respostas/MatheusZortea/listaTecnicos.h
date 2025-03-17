#ifndef _LISTATECNICOS_H
#define _LISTATECNICOS_H

#include "tecnico.h"
#include "data.h"


typedef struct ListaTecnicos ListaTecnicos;


ListaTecnicos *criaListaTecnicos();

void insereTecnicoLista(ListaTecnicos *lt, Tecnico *t);

void desalocaListaTecnicos(ListaTecnicos *lt);

int getQtdTecnicosCadastrados(ListaTecnicos *lt);

Tecnico *getTecnicoNaLista(ListaTecnicos *lt, int i);

void ContabilizaHorasTecnicos(ListaTecnicos *lt, char* cpf, int horas);

void notificaListaTecnicos(ListaTecnicos *lt);

#endif