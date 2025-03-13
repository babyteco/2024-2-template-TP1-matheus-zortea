#ifndef _USUARIO
#define _USUARIO

#define MAX_NOME 100
#define MAX_CPF 14
#define MAX_TEL 14
#define MAX_ATUACAO 5
#define MAX_GENERO 9


typedef struct Tenico Tecnico;

/*
Inicializa alocando os vetores e cria um usuário
Retorna um ponteiro para o usuário inicializado
*/
Tecnico *CriaTecnico();

/*
Le as informações do usuário da entrada padrão
Retorna um ponteiro para o Usuario
*/
Tecnico *LeTecnico();

#endif
