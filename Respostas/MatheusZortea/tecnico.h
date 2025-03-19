#ifndef _TECNICO
#define _TECNICO

#include "data.h"



typedef struct Tecnico Tecnico;


Tecnico *CriaTecnico(char *nome, char *cpf, Data *d, char *telefone, char *genero, char *atuacao, int salario, int disptempo);

Tecnico *LeTecnico();

int getDispTempoTecnico(Tecnico *t);

char *getCpfTecnico(Tecnico *t);

char *getNomeTecnico(Tecnico *t);

char *getTelefoneTecnico(Tecnico *t);

char *getGeneroTecnico(Tecnico *t);

char *getAtuacaoTecnico(Tecnico *t);

int getSalarioTecnico(Tecnico *t);

int getSalarioTecnico(Tecnico *t);

Data *getNascimentoTecnico(Tecnico *t);

int getTempoTrabalhadoTecnico(Tecnico *t);

void AtualizaTempoTrabalhadoTecnico(Tecnico *original, Tecnico *novo);

void modificaHorasTecnico(Tecnico *t, int qtdHoras);

void desalocaTecnico(Tecnico *t);

void notificaTecnico(Tecnico *t);

#endif
