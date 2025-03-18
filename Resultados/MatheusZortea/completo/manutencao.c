#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manutencao.h"

#define MAX_TAM_NOME_MANUTENCAO 100
#define MAX_TAM_LOCAL 100
#define MAX_TAM_ESTADO 20
#define MAX_TAM_SETOR 20


/**
 * Estrutura de um Ticket Manutencao contendo os parametros especificos de um ticket do tipo SOFTWARE
 */
typedef struct Manutencao{
    char nome[MAX_TAM_NOME_MANUTENCAO];
    char estado[MAX_TAM_ESTADO];
    char local[MAX_TAM_LOCAL];
    int tempo;
    char setor[MAX_TAM_SETOR];
} Manutencao;

/**
 * @brief Aloca uma estrutura Manutencao na memória e inicializa os parâmetro necessários
 * @param nome Nome da Manutencao
 * @param categoria Estado da Manutencao
 * @param local lugar do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Manutencao inicializada.
 */
Manutencao *criaManuencao(char *nome, char *estado, char *local){
    Manutencao *m = (Manutencao*) malloc(sizeof(Manutencao));
    m->tempo = 0;
    strcpy(m->nome, nome);
    strcpy(m->estado, estado);
    strcpy(m->local, local);
    return m;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Manutencao
 * @return  Um chamado do Tipo Manutencao
 */
Manutencao *lerManutencao(){
    char nome[MAX_TAM_NOME_MANUTENCAO];
    char estado[MAX_TAM_ESTADO];
    char local[MAX_TAM_LOCAL];
    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", estado);
    scanf("%[^\n]\n", local);
    
    Manutencao *m = criaManuencao(nome, estado, local);

    m->tempo = setTempoEstimadoManutencao(m);
    return m;
}

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Manutencao.
 * Tempo estimado depende da categoria e impacto
 * @param m  Ticket do tipo Manutencao
 */
int setTempoEstimadoManutencao(Manutencao *m){
    int tempoEstado = 0;
    int tempoSetor = 0;
    if (strcmp(m->estado, "RUIM") == 0){
        tempoEstado = 3;
    }
    if (strcmp(m->estado, "REGULAR") == 0){
        tempoEstado = 2;
    }
    if (strcmp(m->estado, "BOM") == 0){
        tempoEstado = 1;
    }

    if (strcmp(m->setor, "RH") == 0){
        tempoSetor = 2;
    }
    if (strcmp(m->setor, "FINANCEIRO") == 0){
        tempoSetor = 3;
    }
    if (strcmp(m->setor, "P&D") == 0){
        tempoSetor = 1;
    }
    if (strcmp(m->setor, "VENDAS") == 0){
        tempoSetor = 1;
    }
    if (strcmp(m->setor, "MARKETING") == 0){
        tempoSetor = 1;
    }
    
    int tempo;
    tempo = tempoEstado * tempoSetor;
    
    return tempo;
}

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Manutencao.
 * @param dado  Ticket do tipo Manutencao
 * @return  Tempo estimado para resolver um ticket do tipo Manutencao
 */
int getTempoEstimadoManutencao(void *dado){
    Manutencao *m = (Manutencao*) dado;
    return m ->tempo;
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'M' para Manutencao
 */
char getTipoManutencao(){
    return 'M';
}

/**
 * @brief  Desaloca um ticket do tipo Manutencao da memória
 * @param dado  Ticket do tipo Manutencao
 */
void desalocaManutencao(void *dado){
    Manutencao *m = (Manutencao*) dado;
    free(m);
}

/**
 * @brief  Imprime um ticket do tipo Manutencao
 * @param dado  Ticket do tipo Manutencao
 */
void notificaManutencao(void *dado){
    Manutencao *m = (Manutencao*) dado;
    printf("- Tipo: Manutencao\n");
    printf("- Nome do item: %s\n", m->nome);
    printf("- Estado de conservacao: %s\n", m->estado);
    printf("- Local: %s\n", m->local);
    printf("- Tempo estimado: %dh\n", m->tempo);
}