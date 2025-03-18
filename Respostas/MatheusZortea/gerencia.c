#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tecnico.h"
#include "usuario.h"
#include "listaTecnicos.h"
#include "listaUsuarios.h"
#include "data.h"
#include "ticket.h"
#include "fila.h"
#include "manutencao.h"
#include "outros.h"
#include "software.h"
#include "gerencia.h"

#define MAX_TAM_TIPO 20
#define MAX_TAM_ACAO 35



void LeCadastraTicket(Fila *f, ListaUsuarios *lu){
    char cpf[MAX_TAM_CPF];
    char tipo[MAX_TAM_TIPO];

    scanf("%[^\n]\n", cpf);
    scanf("%[^\n]\n", tipo);

    if (strcmp(tipo, "MANUTENCAO") == 0) {
        printf("ENTROU PARA LER MANUTENCAO: CPF: %s TIPO: %s\n", cpf, tipo);
        Manutencao *m = lerManutencao();
        
        if(comparaCPF(lu, cpf) != 0) {
            insereTicketFila(f, cpf, m, getTempoEstimadoManutencao, getTipoManutencao, notificaManutencao, desalocaManutencao);
            ContabilizaTicketUsuario(lu, cpf);
        } else {
            desalocaManutencao(m);
        }
    }

    if (strcmp(tipo, "OUTROS") == 0) {
                
        Outros *o = lerOutros();
        printf("CPF SOLICITANTE: %s\n", cpf);
        
        if (comparaCPF(lu, cpf) == 1) {
            printf("PASSOU DO ORIMEIRO IF DA GERENCIA\n");
            insereTicketFila(f, cpf, o, getTempoEstimadoOutros, getTipoOutros, notificaOutros, desalocaOutros);
            printf("PASSOU DA FUNCAO INSERE TICKET NA FILA\n");
            ContabilizaTicketUsuario(lu, cpf);
            printf("PASSOU DO CONTABILIZA TICKET USUARIO\n");
        } else {
            printf("DESALOCOU\n");
            desalocaOutros(o);
        }
    }

    if (strcmp(tipo, "SOFTWARE") == 0) {
        
        printf("ENTROU PARA LER SOFTWARE: CPF: %s TIPO: %s\n", cpf, tipo);

        Software *s = lerSoftware();
        
        if (comparaCPF(lu, cpf) != 0) {
            insereTicketFila(f, cpf, s, getTempoEstimadoSoftware, getTipoSoftware, notificaSoftware, desalocaSoftware);
            ContabilizaTicketUsuario(lu, cpf);
        } else {
            desalocaSoftware(s);
        } 
    } 
}


void RealizaAcao(Fila *f){
    char acao[MAX_TAM_ACAO];
    scanf("%[^\n]\n", acao);

    if (strcmp(acao, "DISTRIBUI") == 0) {
        /* code */
    } 

    if (strcmp(acao, "NOTIFICA") == 0) {
        printf("----- FILA DE TICKETS -----\n");
        notificaFila(f);
        printf("\n---------------------------\n");
    }
    
    if (strcmp(acao, "USUARIOS") == 0) {
        /* code */
    }
    
    if (strcmp(acao, "TECNICOS") == 0){
        /* code */
    }

    if (strcmp(acao, "RANKING TECNICOS") == 0) {
        /* code */
    }
    
    if (strcmp(acao, "RANKING USUARIOS") == 0) {
        /* code */
    }
    
    if (strcmp(acao, "RELATORIO") == 0) {
        /* code */
    }
    
}