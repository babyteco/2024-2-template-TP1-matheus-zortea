#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outros.h"

#define MAX_TAM_LOCAL 100
#define MAX_TAM_DESCRICAO 500

/**
 * Estrutura de um Ticket Outros contendo os parametros especificos de um ticket do tipo Outros
 */
typedef struct Outros{
    char *descricao;
    char *local;
    int nivel;
    int tempo;
} Outros;


/**
 * @brief Aloca uma estrutura Outros na memória e inicializa os parâmetro necessários
 * @param nome Nome da Outros
 * @param categoria Estado da Outros
 * @param local lugar do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Outros inicializada.
 */
Outros *criaOutros(char *descricao, char *local, int nivel){
    Outros *o = (Outros*) malloc(sizeof(Outros));
    o->descricao = (char*) malloc(MAX_TAM_DESCRICAO * sizeof(char));
    o->local = (char*) malloc(MAX_TAM_LOCAL * sizeof(char));
    
    strcpy(o->descricao, descricao);
    strcpy(o->local, local);
    o->nivel = nivel;
    o->tempo = nivel;

    return o;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Outros
 * @return  Um chamado do Tipo Outros
 */
Outros *lerOutros(){
    char *descricao;
    char *local;
    int nivel;
    scanf("%[^\n]\n", descricao);
    scanf("%[^\n]\n", local);
    scanf("%d\n", &nivel);
    Outros *m = criaOutros(descricao, local, nivel);
    return m;
}


/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Outros.
 * @param dado  Ticket do tipo Outros
 * @return  Tempo estimado para resolver um ticket do tipo Outros
 */
int getTempoEstimadoOutros(void *dado){
    Outros *m = (Outros*) dado;
    return m ->tempo;
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'O' para Outros
 */
char getTipoOutros(){
    return 'O';
}

/**
 * @brief  Desaloca um ticket do tipo Outros da memória
 * @param dado  Ticket do tipo Outros
 */
void desalocaOutros(void *dado){
    Outros *o = (Outros*) dado;
    free(o->descricao);
    free(o->local);
    free(o);
}

/**
 * @brief  Imprime um ticket do tipo Outros
 * @param dado  Ticket do tipo Outros
 */
void notificaOutros(void *dado){
    Outros *o = (Outros*) dado;
    printf("- Tipo: Outros\n");
    printf("- Descricao: %s\n", o->descricao);
    printf("- Local: %s\n", o->local);
    printf("- Tempo estimado: %dh\n", o->tempo);
}