#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manutencao.h"

#define MAX_TAM_NOME_MANUTENCAO 100
#define MAX_TAM_LOCAL 100
#define MAX_TAM_ESTADO 10
#define MAX_TAM_SETOR 12


/**
 * Estrutura de um Ticket Manutencao contendo os parametros especificos de um ticket do tipo SOFTWARE
 */
typedef struct Manutencao{
    char *nome;
    char *estado;
    char *local;
    int tempo;
    char *setor;
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
    m->nome = (char*) malloc(MAX_TAM_NOME_MANUTENCAO * sizeof(char));
    m->estado = (char*) malloc(MAX_TAM_ESTADO * sizeof(char));
    m->local = (char*) malloc(MAX_TAM_LOCAL * sizeof(char));
    m->setor = (char*) malloc(MAX_TAM_SETOR * sizeof(char));
    m->tempo = 0;
    return m;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Manutencao
 * @return  Um chamado do Tipo Manutencao
 */
Manutencao *lerManutencao(){
    char *nome;
    char *estado;
    char *local;
    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", estado);
    scanf("%[^\n]\n", local);
    Manutencao *m = criaManuencao(nome, estado, local);
    return m;
}

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Manutencao.
 * Tempo estimado depende da categoria e impacto
 * @param m  Ticket do tipo Manutencao
 */
void setTempoEstimadoManutencao(Manutencao *m){
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

    m->tempo = tempoEstado * tempoSetor;
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
    free(m->nome);
    free(m->estado);
    free(m->local);
    free(m->setor);
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