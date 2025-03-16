#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"usuario.h"
#include"data.h"

#define MAX_NOME 100
#define MAX_CPF 14
#define MAX_TEL 14
#define MAX_SETOR 10
#define MAX_GENERO 9

typedef struct Usuario{
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    Data nascimento;
    char telefone[MAX_TEL];
    char genero[MAX_GENERO];
    char setor[MAX_SETOR];
    int qtdTickets;
} Usuario;

/*
Inicializa alocando os vetores e cria um usuário
Retorna um ponteiro para o usuário inicializado
*/
Usuario *CriaUsuario(char *nome, char *cpf, Data d, char *telefone, char *genero, char *setor){
    Usuario *u = (Usuario*) malloc(sizeof(Usuario));
    strcpy(u->nome, nome);
    strcpy(u->cpf, cpf);
    strcpy(u->telefone, telefone);
    strcpy(u->genero, genero);
    strcpy(u->setor, setor);
    u->nascimento = d;
    u->qtdTickets = 0;
    return u; 
}

/*
Le as informações do usuário da entrada padrão
Retorna um ponteiro para o Usuario
*/
Usuario *LeUsuario(){
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    Data nascimento;
    char telefone[MAX_TEL];
    char genero[MAX_GENERO];
    char setor[MAX_SETOR];
    
    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", cpf);
    nascimento = LeData();
    scanf("%[^\n]\n", telefone);
    scanf("%[^\n]\n", genero);
    scanf("%[^\n]\n", setor);
    
    Usuario *u = CriaUsuario(nome, cpf, nascimento, telefone, genero, setor);
    
    return u;
}

void desalocaUsuario(Usuario *u){
    free(u);
}

int getTicketsSolicitados(Usuario *u){
    return u->qtdTickets;
}

void AcrescentaTicketUsuario(Usuario *u){
    u->qtdtickets++;
}

void notificaUsuario(Usuario *u){
    printf("- Nome: %s\n", u->nome);
    printf("- CPF: %s\n", u->cpf);
    printf("- Data de Nascimento: %d/%d/%d\n", u->nascimento.dia, u->nascimento.mes, u->nascimento.ano);
    printf("- Telefone: %s\n" , u->telefone);
    printf("- Genero: %s\n", u->genero);
    printf("- Setor: %s\n", u->setor);
    printf("- Tickets solicitados: %d\n", u->qtdTickets);
}
