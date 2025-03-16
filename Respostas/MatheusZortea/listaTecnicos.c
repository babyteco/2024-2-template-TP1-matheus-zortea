#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "listaTecnicos.h"
#include "data.h"


typedef struct ListaTecnicos{
    Tecnico **t;
    int qtdTecnicos;
    int capacidade;
} ListaTecnicos;


ListaTecnicos *criaListaTecnicos(){
    ListaTecnicos *lt = (ListaTecnicos*) malloc(sizeof(ListaTecnicos));
    lt->t = (Tecnicos**) malloc(2 * sizeof(Tecnicos*));
    lt->qtdTecnicos = 0;
    lt->capacidade = 2;
}



void insereUsuarioLista(ListaTecnicos *lt, char *nome, char *cpf, Data d, char *telefone, char *genero, char *atuacao, int salario, int dispTempo){
    if (lt->capacidade == lt->qtdTecnicos){
        lt->t = (Usuario**) realloc(lt->t, 2 * sizeof(Usuario*));
        lt->capacidade += 2;
    }
    
    lt->t[lt->qtdTecnicos] = criaTecnico(nome, cpf, d, telefone, genero, atuacao, salario, dispTempo);

    lt->qtdTecnicos++;
}

void desalocaListaTecnicos(ListaTecnicos *lt){
    for (int i = 0; i < lt->qtdTecnicos; i++){
        desalocaTecnico(lt->t[i]);
    }
    free(t);
    free(lt);
}

int getQtdTecnicosCadastrados(ListaTecnicos *lt){
    return lt->qtdTecnicos;
}

Tecnico *getTecnicoNaLista(ListaTecnicos *lt, int i){
    return lt->t[i];
}

void ContabilizaHorasTecnicos(ListaTecnicos *lt, char* cpf, int horas){
    for (int i = 0; i < lt->qtdTecnicos; i++){
        if (strcmp(lt->t[i]->cpf, cpf) == 0){
            modificaHorasTecnico(lt->t[i], horas);
            break;
        }
    }
}


void notificaListaTecnicos(ListaTecnicos *lt){
    printf("----- BANCO DE TECNICOS -----\n");
    for (int i = 0; i < lt->qtdTecnicos; i++){
        printf("--------------------\n");
        notificaTecnico(lt->t[i]);
        if (i == lt->qtdTecnicos){
            printf("----------------------------\n");
        } else {
            printf("--------------------\n");
        }
    }
    printf("\n");
}

