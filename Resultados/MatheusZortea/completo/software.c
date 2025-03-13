#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "software.h"

#define MAX_TAM_NOME_SOFTWARE 100
#define MAX_TAM_CAT 25
#define MAX_TAM_MOTIVO 200

#define TEMPO_ESTIMADO_BUG 3
#define TEMPO_ESTIMADO_OUTROS 2
#define TEMPO_ESTIMADO_DUVIDA 1

/**
 * Estrutura de um Ticket Software contendo os parametros especificos de um ticket do tipo SOFTWARE
 */
typedef struct Software{
    char *nome;
    char *categoria;
    int impacto;
    char *motivo;
    int tempo;
} Software;

//os inteiros da struct devem ser ponteiros? Ou basta a struct sem ponteiro q ja salva tudio?


/**
 * @brief Aloca uma estrutura Software na memória e inicializa os parâmetro necessários
 * @param nome Nome do software
 * @param categoria Categoria do software
 * @param impacto Impacto do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Software inicializada.
 */
Software *criaSoftware(char *nome, char *categoria, int impacto, char *motivo){
    Software *s = (Software*) malloc(sizeof(Software));
    s->nome = (char*) malloc(MAX_TAM_NOME_SOFTWARE * sizeof(char));
    s->categoria = (char*) malloc(MAX_TAM_CAT * sizeof(char));
    s->motivo = (char*) malloc(MAX_TAM_MOTIVO * sizeof(char));
    
    strcpy(s->nome, nome);
    strcpy(s->categoria, categoria);
    strcpy(s->motivo, motivo);
    s->impacto = impacto;

    return s;
}


/**
 * @brief Lê da entrada padrão um  ticket do TIPO software
 * @return  Um chamado do Tipo Software
 */
Software *lerSoftware(){
    Software *s;
    char nome[MAX_TAM_NOME_SOFTWARE];
    char categoria[MAX_TAM_CAT];
    char motivo[MAX_TAM_MOTIVO];
    int impacto;
    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", categoria);
    scanf("%d\n", &impacto);
    scanf("%[^\n]\n", motivo);
    s = criaSoftware(nome, categoria, impacto, motivo);
    setTempoEstimadoSoftware(s);
    return s;
}


/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Software.
 * Tempo estimado depende da categoria e impacto
 * @param s  Ticket do tipo Software
 */
void setTempoEstimadoSoftware(Software *s){
    if(strcmp(s->categoria, "BUG") == 0){
        s->tempo = TEMPO_ESTIMADO_BUG + s->impacto;    
    } else if(strcmp(s->categoria, "DUVIDAS")){
        s->tempo = TEMPO_ESTIMADO_DUVIDA + s->impacto;
    } else if(strcmp(s->categoria, "OUTROS")){
        s->tempo = TEMPO_ESTIMADO_OUTROS + s->impacto;
    }
}

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Software.
 * @param dado  Ticket do tipo Software
 * @return  Tempo estimado para resolver um ticket do tipo Software
 */
int getTempoEstimadoSoftware(void *dado){
    Software *a = (Software*) dado;
    return a->tempo; 
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'S' para Software
 */
char getTipoSoftware(){
    return 'S';
}

/**
 * @brief  Desaloca um ticket do tipo Software da memória
 * @param s  Ticket do tipo Software
 */
void desalocaSoftware(void *s){
    Software *a = (Software*) s;
    free(a->categoria); 
    free(a->nome);
    free(a->motivo);
    free(a);
}

/**
 * @brief  Imprime um ticket do tipo Software
 * @param dado  Ticket do tipo Software
 */
void notificaSoftware(void *dado){
    Software *a = (Software*) dado;
    printf("- Tipo: Software\n");
    printf("- Nome do software: %s\n", a->nome);
    printf("- Categoria: %s\n", a->categoria);
    printf("- Nível do impacto: %d\n", a->impacto);
    printf("- Motivo: %s\n", a->motivo);
    printf("- Tempo estimado: %dh\n", a->tempo);
}
