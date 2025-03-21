#ifndef _LISTATECNICOS_H
#define _LISTATECNICOS_H

#include "tecnico.h"
#include "data.h"


typedef struct ListaTecnicos ListaTecnicos;


ListaTecnicos *criaListaTecnicos();

void insereTecnicoLista(ListaTecnicos *lt, Tecnico *t);

int comparaCPFTecnicos(ListaTecnicos *lt, char *cpf);

void desalocaListaTecnicos(ListaTecnicos *lt);

int getQtdTecnicosCadastrados(ListaTecnicos *lt);

Tecnico *getTecnicoNaLista(ListaTecnicos *lt, int i);

void ContabilizaHorasTecnicos(ListaTecnicos *lt, char* cpf, int horas);

void TrocaPosicaoTecnicos(ListaTecnicos *lt, int i);

ListaTecnicos *CopiaListaTecnicos(ListaTecnicos *lt);

void RankingTecnico(ListaTecnicos *lt);

void notificaListaTecnicos(ListaTecnicos *lt);

void notificaRankingTecnicos(ListaTecnicos *lt);

int MediaIdadeTecnicos(ListaTecnicos *lt);

int MediaTempoTrabalhadoTecnicos(ListaTecnicos *lt);

#endif