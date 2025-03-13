#include<stdio.h>
#include<stdlib.h>
#include"tecnico.h"
#include"data.h"

typedef struct Tenico{
    char *nome;
    char *cpf;
    Data *nascimento;
    char *telefone;
    char *genero;
    char *atuacao;
    int salario;
    int dispTempo;
} Tecnico;

/*
Inicializa alocando os vetores e cria um usuário, inicializando os inteiros como -1
Retorna um ponteiro para o usuário inicializado
*/
Tecnico *CriaTecnico(){  
    Tecnico *t = (Tecnico*) malloc(sizeof(Tecnico));
    t->nome = (char*) malloc(MAX_NOME * sizeof(char));
    t->cpf = (char*) malloc(MAX_CPF * sizeof(char));
    t->telefone = (char*) malloc(MAX_TEL * sizeof(char));
    //u->nascimento = InicializaData(&t->nascimento);
    t->nascimento = InicializaData(t->nascimento);
    t->genero = (char*) malloc(MAX_GENERO * sizeof(char));
    t->atuacao = (char*) malloc(MAX_ATUACAO * sizeof(char));
    t->dispTempo = -1;
    t->salario = -1;
    return t;
}

/*
Le as informações do usuário da entrada padrão
Retorna um ponteiro para o Usuario
*/
Tecnico *LeTecnico(){
    Tecnico *t = CriaTecnico();
    scanf("%[^\n]\n", &t->nome);
    scanf("%[^\n]\n", &t->cpf);
    t->nascimento = LeData();
    scanf("%[^\n]\n", &t->telefone);
    scanf("%[^\n]\n", &t->genero);
    scanf("%[^\n]\n", &t->atuacao);
    scanf("%d\n", &t->dispTempo);
    scanf("%d\n", &t->salario);
    return t;
}
