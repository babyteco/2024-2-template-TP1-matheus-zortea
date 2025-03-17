#ifndef _USUARIO
#define _USUARIO

#include "data.h"

#define MAX_NOME 100
#define MAX_CPF 14
#define MAX_TEL 14
#define MAX_SETOR 10
#define MAX_GENERO 9


typedef struct Usuario Usuario;

Usuario *CriaUsuario(char *nome, char *cpf, Data d, char *telefone, char *genero, char *setor);

Usuario *LeUsuario();

void desalocaUsuario(Usuario *u);

int getTicketsSolicitados(Usuario *u);

char *getCpfUsuario(Usuario *u);

void AcrescentaTicketUsuario(Usuario *u);

void notificaUsuario(Usuario *u);

#endif
