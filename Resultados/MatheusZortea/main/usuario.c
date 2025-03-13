#include<stdio.h>
#include<stdlib.h>
#include"usuario.h"
#include"data.h"


typedef struct Usuario{
    char *nome;
    char *cpf;
    Data *nascimento;
    char *telefone;
    char *genero;
    char *setor;
} Usuario;

/*
Inicializa alocando os vetores e cria um usuário
Retorna um ponteiro para o usuário inicializado
*/
Usuario *CriaUsuario(){
    Usuario *u = (Usuario*) malloc(sizeof(Usuario));
    u->nome = (char*) malloc(MAX_NOME * sizeof(char));
    u->cpf = (char*) malloc(MAX_CPF * sizeof(char));
    u->telefone = (char*) malloc(MAX_TEL * sizeof(char));
    //u->nascimento = InicializaData(&u->nascimento);
    u->nascimento = InicializaData(u->nascimento);
    u->genero = (char*) malloc(MAX_GENERO * sizeof(char));
    u->setor = (char*) malloc(MAX_SETOR * sizeof(char));

    return u; 
}

/*
Le as informações do usuário da entrada padrão
Retorna um ponteiro para o Usuario
*/
Usuario *LeUsuario(){
    Usuario *u = CriaUsuario();
    scanf("%[^\n]\n", &u->nome);
    scanf("%[^\n]\n", &u->cpf);
    u->nascimento = LeData();
    scanf("%[^\n]\n", &u->telefone);
    scanf("%[^\n]\n", &u->genero);
    scanf("%[^\n]\n", &u->setor);

    return u;
}

