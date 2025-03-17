#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "listaUsuarios.h"
#include "ticket.h"

typedef struct ListaUsuarios{
    Usuario **u;
    int qtdUsuarios;
    int capacidade;
} ListaUsuarios;


ListaUsuarios *criaListaUsuarios(){
    ListaUsuarios *lu = (ListaUsuarios*) malloc(sizeof(ListaUsuarios));
    lu->u = (Usuario**) malloc(2 * sizeof(Usuario*));
    lu->qtdUsuarios = 0;
    lu->capacidade = 2;
}



void insereUsuarioLista(ListaUsuarios *lu, Usuario *u){
    if (lu->capacidade == lu->qtdUsuarios){
        lu->u = (Usuario**) realloc(lu->u, 2 * sizeof(Usuario*));
        lu->capacidade += 2;
    }
    
    lu->u[lu->qtdUsuarios] = u;
    
    lu->qtdUsuarios++;
}

void desalocaListaUsuarios(ListaUsuarios *lu){
    for (int i = 0; i < lu->qtdUsuarios; i++){
        desalocaUsuario(lu->u[i]);
    }
    free(lu->u);
    free(lu);
}

int getQtdUsuariosCadastrados(ListaUsuarios *lu){
    return lu->qtdUsuarios;
}


/**
 * @brief Recupera um ticket na fila de processamento. Um ticket deve ser recuperado sempre na i-ésima posição.
 * @param f  Fila que contém o ticket
 * @param i  Posição do ticket na fila
 * @return  Ticket recuperado da fila
 */
Ticket *getUsuarioNaLista(ListaUsuarios *lu, int i){
    return lu->u[i];
}

void ContabilizaTicketUsuario(ListaUsuarios *lu, char* cpf){
    for (int i = 0; i < lu->qtdUsuarios; i++){
        if (strcmp(getCpfUsuario(lu->u[i]), cpf) == 0){
            AcrescentaTicketUsuario(lu->u[i]);
            break;
        }
    }
}

/**
 * @brief A função notificaFila imprime todos os tickets na Fila f
 * @param f  Fila inicializada contendo zero ou mais tickets.
 */
void notificaListaUsuarios(ListaUsuarios *lu){
    printf("----- BANCO DE USUARIOS -----\n");
    for (int i = 0; i < lu->qtdUsuarios; i++){
        printf("--------------------\n");
        notificaUsuario(lu->u[i]);
        if (i == lu->qtdUsuarios){
            printf("----------------------------\n");
        } else {
            printf("--------------------\n");
        }
    }
    printf("\n");
}

