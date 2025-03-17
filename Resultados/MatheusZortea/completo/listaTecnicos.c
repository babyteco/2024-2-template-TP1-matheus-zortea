#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tecnico.h"
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
    lt->t = (Tecnico**) malloc(2 * sizeof(Tecnico*));
    lt->qtdTecnicos = 0;
    lt->capacidade = 2;
    return lt;
}



void insereTecnicoLista(ListaTecnicos *lt, Tecnico *t){
    if (lt->capacidade == lt->qtdTecnicos){
        lt->t = (Tecnico**) realloc(lt->t, 2 * sizeof(Tecnico*));
        lt->capacidade += 2;
    }
    
    lt->t[lt->qtdTecnicos] = t;

    lt->qtdTecnicos++;
}

void desalocaListaTecnicos(ListaTecnicos *lt){
    for (int i = 0; i < lt->qtdTecnicos; i++){
        desalocaTecnico(lt->t[i]);
    }
    free(lt->t);
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
        if (strcmp(getCpf(lt->t[i]), cpf) == 0){
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

