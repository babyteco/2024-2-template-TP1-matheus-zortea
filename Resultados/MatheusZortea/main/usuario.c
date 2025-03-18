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
    printf("INFORMACOES AO PASSAR PARA O USUARIO:\n");
    strcpy(u->nome, nome);
    printf("u->nome: %s  nome: %s\n", u->nome, nome);
    strcpy(u->cpf, cpf);
    printf("u->cpf: %s cpf: %s\n", u->cpf, cpf);
    strcpy(u->telefone, telefone);
    printf("TELEFONE: %s\n", u->telefone);
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
    Data *nascimento;
    char telefone[MAX_TEL];
    char genero[MAX_GENERO];
    char setor[MAX_SETOR];
    
    scanf("%[^\n]\n", nome);
    printf("ACABOU DE LER O NOME: %s\n", nome);
    scanf("%[^\n]\n", cpf);
    printf("ACABOU DE LER O CPF: %s\n", cpf);
    nascimento = LeData();
    scanf("%[^\n]\n", telefone);
    printf("ACABOU DE LER O TELEFOME: %s\n", telefone);
    scanf("%[^\n]\n", genero);
    printf("ACABOU DE LER O GENERO: %s\n", genero);
    scanf("%[^\n]\n", setor);
    printf("ACABOU DE LER O SETOR: %s\n", setor);
    

    return CriaUsuario(nome, cpf, nascimento, telefone, genero, setor);
    
    //return u;
}

void desalocaUsuario(Usuario *u){
    DesalocaData(u->nascimento);
    free(u);
}

int getTicketsSolicitados(Usuario *u){
    return u->qtdTickets;
}

char *getCpfUsuario(Usuario *u){
    return u->cpf;
}

void AcrescentaTicketUsuario(Usuario *u){
    u->qtdTickets++;
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
