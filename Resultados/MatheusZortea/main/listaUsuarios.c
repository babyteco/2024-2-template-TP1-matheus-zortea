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
    return lu;
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


Usuario *getUsuarioNaLista(ListaUsuarios *lu, int i){
    return lu->u[i];
}

//retorna 1 se ele existir, 0 caso contrario
int comparaCPF(ListaUsuarios *lu, char *cpf){
    

    for (int i = 0; i < lu->qtdUsuarios; i++){
        if (strcmp(getCpfUsuario(lu->u[i]), cpf) == 0){
            return 1;
        }
    }
    return 0;
}

void ContabilizaTicketUsuario(ListaUsuarios *lu, char* cpf){
    int flag = comparaCPF(lu, cpf);
    if (flag != 0){
        AcrescentaTicketUsuario(lu->u[flag]);    
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

