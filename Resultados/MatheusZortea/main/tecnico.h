#ifndef _TECNICO
#define _TECNICO

#include "data.h"



typedef struct Tecnico Tecnico;


Tecnico *CriaTecnico(char *nome, char *cpf, Data *d, char *telefone, char *genero, char *atuacao, int salario, int disptempo);

Tecnico *LeTecnico();

int getDispTempo(Tecnico *t);

char *getAtuacao(Tecnico *t);

char *getCpf(Tecnico *t);

void modificaHorasTecnico(Tecnico *t, int qtdHoras);

void desalocaTecnico(Tecnico *t);

void notificaTecnico(Tecnico *t);

#endif
