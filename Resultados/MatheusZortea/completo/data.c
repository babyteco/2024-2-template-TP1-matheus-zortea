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
    return d;
}

/*
Cria e le uma data
Retorna um ponteiro para data
*/
Data* LeData(){
    Data *d = InicializaData();
    scanf("%d/%d/%d\n",&d->dia, &d->mes, &d->ano);
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

/*
Imprime a data especificada
*/
void ImprimeData(Data *d){
    printf("%d/%d/%d\n", d->dia, d->mes, d->ano);
}

void DesalocaData(Data *d){
    free(d);
}