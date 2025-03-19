#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"usuario.h"
#include"data.h"

#define MAX_NOME 100
#define MAX_CPF 20
#define MAX_TEL 20
#define MAX_SETOR 20
#define MAX_GENERO 20

typedef struct Usuario{
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    Data *nascimento;
    char telefone[MAX_TEL];
    char genero[MAX_GENERO];
    char setor[MAX_SETOR];
    int qtdTickets;
} Usuario;

/*
Inicializa alocando os vetores e cria um usuário
Retorna um ponteiro para o usuário inicializado
*/
Usuario *CriaUsuario(char *nome, char *cpf, Data *d, char *telefone, char *genero, char *setor){
    Usuario *u = (Usuario*) malloc(sizeof(Usuario));
    u->nascimento = InicializaData();
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
    Usuario *u = (Usuario*) malloc(sizeof(Usuario));
    u->nascimento = InicializaData();
        
    scanf("%[^\n]\n", u->nome);
    scanf("%[^\n]\n", u->cpf);
    u->nascimento = LeData();
    scanf("%[^\n]\n", u->telefone);
    scanf("%[^\n]\n", u->genero);
    scanf("%[^\n]\n", u->setor);

    return u;
}

void desalocaUsuario(Usuario *u){
    DesalocaData(u->nascimento);
    free(u);
}

int getTicketsSolicitados(Usuario *u){
    return u->qtdTickets;
}
    
char *getNomeUsuario(Usuario *u){
    return u->nome;
}

char *getCpfUsuario(Usuario *u){
    return u->cpf;
}

Data *getNascimentoUsuario(Usuario *u){
    return u->nascimento;
}

char *getTelefoneUsuario(Usuario *u){
    return u->telefone;
}

char *getGeneroUsuario(Usuario *u){
    return u->genero;
}

char *getSetorUsuario(Usuario *u){
    return u->setor;
}

void AtualizaQtdTickets(Usuario *antigo, Usuario *novo){
    novo->qtdTickets = antigo->qtdTickets;
}

void AcrescentaTicketUsuario(Usuario *u){
    u->qtdTickets = u->qtdTickets + 1;
}

void notificaUsuario(Usuario *u){
    printf("- Nome: %s\n", u->nome);
    printf("- CPF: %s\n", u->cpf);
    printf("- Data de Nascimento: ");
    ImprimeData(u->nascimento);
    printf("- Telefone: %s\n" , u->telefone);
    printf("- Genero: %s\n", u->genero);
    printf("- Setor: %s\n", u->setor);
    printf("- Tickets solicitados: %d\n", u->qtdTickets);
}
