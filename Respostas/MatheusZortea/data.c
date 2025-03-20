#include<stdio.h>
#include<stdlib.h>
#include"data.h"


typedef struct Data{
    int dia;
    int mes;
    int ano;
} Data;



/*
Inicializa uma data alocando memória para ela
retorna o ponteiro para a data inicializada
*/
Data* InicializaData(){
    Data *d = (Data*) malloc(sizeof(Data));
    d->ano = 0;
    d->mes = 0;
    d->dia = 0;
    return d;
}

Data* CriaData(int dia, int mes, int ano){
    Data *d = (Data*) malloc(sizeof(Data));
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;
    return d;
}

/*
Cria e le uma data
Retorna um ponteiro para data
*/
Data* LeData(){
    Data *d;

    int dia;
    int mes;
    int ano;

    scanf("%d/%d/%d\n",&dia, &mes, &ano);

    d = CriaData(dia, mes, ano);

    return d;
}

/*
Calcula qual de duas datas e mais velha
Retorna:
1 se d1 for mais antiga 
-1 se d2 for mais antiga
0 se forem iguais
*/
int DiferencaDatas(Data *d1, Data *d2){
    if (d1->ano <= d2->ano){
        if (d1->ano < d2->ano){
            return 1;
        }
        if (d1->mes <= d2->mes){
            if (d1->mes < d2->mes){
                return 1;
            } 
            if(d1->dia < d2->dia){
                return 1;
            }
            if(d1->dia == d2->dia){
                return 0;
            }
        } 
    }
    return -1;
}

Data *CopiaData(Data *d){
    Data *novadata = InicializaData();
    novadata->dia = d->dia;   
    novadata->mes = d->mes;   
    novadata->ano = d->ano;   
    return novadata;
}

int DifAnosData(Data *d, Data *atual) {
    int diferenca = atual->ano - d->ano;

    // Se o mês da data atual for menor que o mês da data d, ou se for o mesmo mês,
    // mas o dia da data atual for anterior ao dia da data d, subtrai 1 da diferença
    if (atual->mes < d->mes || (atual->mes == d->mes && atual->dia < d->dia)) {
        diferenca--;
    }

    return diferenca;
}

/*
Imprime a data especificada
*/
void ImprimeData(Data *d){
    printf("%d/%d/%d\n", d->dia, d->mes, d->ano);
}

void DesalocaData(Data *d){
    free(d);
}