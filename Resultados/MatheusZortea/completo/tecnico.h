#ifndef _TECNICO
#define _TECNICO

#include "data.h"


#define MAX_NOME 100
#define MAX_CPF 14
#define MAX_TEL 14
#define MAX_ATUACAO 5
#define MAX_GENERO 9


typedef struct Tecnico Tecnico;


Tecnico *CriaTecnico(char *nome, char *cpf, Data d, char *telefone, char *genero, char *atuacao, int salario, int disptempo);

Tecnico *LeTecnico();

int getDispTempo(Tecnico *t);

char *getAtuacao(Tecnico *t);

char *getCpf(Tecnico *t);

void modificaHorasTecnico(Tecnico *t, int qtdHoras);

void notificaTecnico(Tecnico *t);

#endif
