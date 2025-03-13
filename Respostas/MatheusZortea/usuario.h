#ifndef _USUARIO
#define _USUARIO

#define MAX_NOME 100
#define MAX_CPF 14
#define MAX_TEL 14
#define MAX_SETOR 10
#define MAX_GENERO 9


typedef struct Usuario Usuario;

/*
Inicializa alocando os vetores e cria um usuário
Retorna um ponteiro para o usuário inicializado
*/
Usuario *CriaUsuario();

/*
Le as informações do usuário da entrada padrão
Retorna um ponteiro para o Usuario
*/
Usuario *LeUsuario();

#endif
