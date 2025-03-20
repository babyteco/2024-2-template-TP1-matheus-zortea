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
        lt->t = (Tecnico**) realloc(lt->t, (lt->capacidade + 2) * sizeof(Tecnico*));
        lt->capacidade += 2;
    }

    int flag = comparaCPFTecnicos(lt, getCpfTecnico(t));
       
    if (flag == 0){
        lt->t[lt->qtdTecnicos] = t;
        lt->qtdTecnicos++;
    } else {
        desalocaTecnico(t);
    }
}

//retorna i se ele existir, 0 caso contrario, -1 se i=0
int comparaCPFTecnicos(ListaTecnicos *lt, char *cpf){
    
    for (int i = 0; i < lt->qtdTecnicos; i++){
        if (strcmp(getCpfTecnico(lt->t[i]), cpf) == 0){
            if (i != 0){
                return i;
            } else {
                return -1;
            }                
        }
    }
    return 0;
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
        if (strcmp(getCpfTecnico(lt->t[i]), cpf) == 0){
            modificaHorasTecnico(lt->t[i], horas);
            break;
        }
    }
}

void TrocaPosicaoTecnicos(ListaTecnicos *lt, int i){
    Tecnico *temp = lt->t[i];
    lt->t[i] = lt->t[i+1];
    lt->t[i+1] = temp;
}

ListaTecnicos *CopiaListaTecnicos(ListaTecnicos *lt) {

    ListaTecnicos *novaLista = criaListaTecnicos();
    int qtdTecnicos = lt->qtdTecnicos;

    // Percorrer a lista original e copiar cada usuário
    for (int i = 0; i < qtdTecnicos; i++) {
        Tecnico *tecnicoOriginal = getTecnicoNaLista(lt, i);

         // Criar cópia da Data para evitar problemas de ponteiro
        Data *novaData = CopiaData(getNascimentoTecnico(tecnicoOriginal));

        // Criar um novo usuário com os mesmos dados
        Tecnico *novoTecnico = CriaTecnico(
            getNomeTecnico(tecnicoOriginal),
            getCpfTecnico(tecnicoOriginal),
            novaData,
            getTelefoneTecnico(tecnicoOriginal),
            getGeneroTecnico(tecnicoOriginal),
            getAtuacaoTecnico(tecnicoOriginal),
            getSalarioTecnico(tecnicoOriginal),
            getDispTempoTecnico(tecnicoOriginal)
        );

        AtualizaTempoTrabalhadoTecnico(tecnicoOriginal, novoTecnico);

        // Inserir o novo tecnico na nova lista
        insereTecnicoLista(novaLista, novoTecnico);

    }

    return novaLista;
}

/*FAZ UMA COPIA DA LISTA DE USUARIOS, ORDENA ELA E IMPRIME*/
void RankingTecnico(ListaTecnicos *lt) {
    ListaTecnicos *listaOrdenada = CopiaListaTecnicos(lt);

    //bubble sort para colocar os tecnicos com mais tempo trabalhado primeiros
    for (int i = 0; i < lt->qtdTecnicos - 1; i++){
        for (int j = 0; j < lt->qtdTecnicos - i - 1; j++){
            if (getTempoTrabalhadoTecnico(listaOrdenada->t[j]) < getTempoTrabalhadoTecnico(listaOrdenada->t[j+1])) {
                TrocaPosicaoTecnicos(listaOrdenada, j);
            }
            /*SE FOR IGUAL PEGA POR ORDEM ALFABETICA*/
            else if(getTempoTrabalhadoTecnico(listaOrdenada->t[j]) == getTempoTrabalhadoTecnico(listaOrdenada->t[j+1])){
                if (strcmp(getNomeTecnico(listaOrdenada->t[j+1]), getNomeTecnico(listaOrdenada->t[j])) < 0){
                    TrocaPosicaoTecnicos(listaOrdenada, j);
                }
            }    
        }    
    }

    notificaRankingTecnicos(listaOrdenada);
}

void notificaListaTecnicos(ListaTecnicos *lt){
    printf("----- BANCO DE TECNICOS -----\n");
    for (int i = 0; i < lt->qtdTecnicos; i++){
        printf("--------------------\n");
        notificaTecnico(lt->t[i]);
    }
    printf("----------------------------\n");
    printf("\n");
}

void notificaRankingTecnicos(ListaTecnicos *lt){
    printf("----- RANKING DE TECNICOS -----\n");
    for (int i = 0; i < lt->qtdTecnicos; i++){
        printf("--------------------\n");
        notificaTecnico(lt->t[i]);     
    }
    printf("-------------------------------\n");
    printf("\n");
}

int MediaIdadeTecnicos(ListaTecnicos *lt){
    //18/02/2025 dia do trabalho
    Data *d = CriaData(18, 2, 2025);
    int somaIdades = 0;
    for (int i = 0; i < lt->qtdTecnicos; i++){
        somaIdades = somaIdades + DifAnosData(getNascimentoTecnico(lt->t[i]), d);
    }
    somaIdades = somaIdades / lt->qtdTecnicos;
    
    DesalocaData(d);
    return somaIdades;
}

int MediaTempoTrabalhadoTecnicos(ListaTecnicos *lt){
    int somaTempo = 0;
    for (int i = 0; i < lt->qtdTecnicos; i++){
        somaTempo = somaTempo + getTempoTrabalhadoTecnico(lt->t[i]);
    }
    somaTempo = somaTempo / lt->qtdTecnicos;
    
    return somaTempo;
}