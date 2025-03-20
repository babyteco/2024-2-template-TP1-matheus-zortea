#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tecnico.h"
#include"data.h"

#define MAX_NOME 100
#define MAX_CPF 20
#define MAX_TEL 20
#define MAX_ATUACAO 20
#define MAX_GENERO 20

typedef struct Tecnico{
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    Data *nascimento;
    char telefone[MAX_TEL];
    char genero[MAX_GENERO];
    char atuacao[MAX_ATUACAO];
    int salario;
    int dispTempo;
    int tempoTrabalhado;
} Tecnico;

/*
Inicializa alocando os vetores e cria um usuário, inicializando os inteiros como -1
Retorna um ponteiro para o usuário inicializado
*/
Tecnico *CriaTecnico(char *nome, char *cpf, Data *d, char *telefone, char *genero, char *atuacao, int salario, int disptempo){  
    Tecnico *t = (Tecnico*) malloc(sizeof(Tecnico));
    strcpy(t->nome, nome);
    strcpy(t->cpf, cpf);
    strcpy(t->telefone , telefone);     
    t->nascimento = d;
    strcpy(t->genero, genero);
    strcpy(t->atuacao, atuacao);
    t->dispTempo = disptempo;
    t->salario = salario;
    t->tempoTrabalhado = 0;
    return t;
}

/*
Le as informações do usuário da entrada padrão
Retorna um ponteiro para o Usuario
*/
Tecnico *LeTecnico(){
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    Data *nascimento;
    char telefone[MAX_TEL];
    char genero[MAX_GENERO];
    char atuacao[MAX_ATUACAO];
    int salario;
    int dispTempo;

    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", cpf);
    nascimento = LeData();
    scanf("%[^\n]\n", telefone);
    scanf("%[^\n]\n", genero);
    scanf("%[^\n]\n", atuacao);
    scanf("%d\n", &dispTempo);
    scanf("%d\n", &salario);
    Tecnico *t = CriaTecnico(nome, cpf, nascimento, telefone, genero, atuacao, salario, dispTempo);
    return t;
}

void desalocaTecnico(Tecnico *t){
    DesalocaData(t->nascimento);
    free(t);
}

int getDispTempoTecnico(Tecnico *t){
    return t->dispTempo;
}

char *getAtuacaoTecnico(Tecnico *t){
    return t->atuacao;
}

char *getCpfTecnico(Tecnico *t){
    return t->cpf;
}

char *getNomeTecnico(Tecnico *t){
    return t->nome;
}

char *getTelefoneTecnico(Tecnico *t){
    return t->telefone;
}

char *getGeneroTecnico(Tecnico *t){
    return t->genero;
}

int getSalarioTecnico(Tecnico *t){
    return t->salario;
}

Data *getNascimentoTecnico(Tecnico *t){
    return t->nascimento;
}

int getTempoTrabalhadoTecnico(Tecnico *t){
    return t->tempoTrabalhado;
}

void AtualizaTempoTrabalhadoTecnico(Tecnico *original, Tecnico *novo){
    novo->tempoTrabalhado = original->tempoTrabalhado;
}

void modificaHorasTecnico(Tecnico *t, int qtdHoras){
    t->dispTempo = t->dispTempo - qtdHoras;
    t->tempoTrabalhado = t->tempoTrabalhado + qtdHoras;
}

void notificaTecnico(Tecnico *t){
    printf("- Nome: %s\n", t->nome);
    printf("- CPF: %s\n", t->cpf);
    printf("- Data de Nascimento: ");
    ImprimeData(t->nascimento);
    printf("- Telefone: %s\n" , t->telefone);
    printf("- Genero: %s\n", t->genero);
    printf("- Area de Atuacao: %s\n", t->atuacao);
    printf("- Salario: %d.00\n", t->salario);
    printf("- Disponibilidade: %dh\n", t->dispTempo);
    printf("- Tempo Trabalhado: %dh\n", t->tempoTrabalhado);
}