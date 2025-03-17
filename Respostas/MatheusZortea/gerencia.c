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



Ticket *LeCadastraTicket(Fila *f, ListaUsuarios *lu){
    char cpf[MAX_TAM_CPF];
    char tipo[MAX_TAM_TIPO];

    scanf("%[^\n]\n", cpf);
    scanf("%[^\n]\n", tipo);

    if (strcmp(tipo, "MANUTENCAO") == 0) {
        Manutencao *m; 
        m = lerManutencao();
        
        if(comparaCPF(lu, cpf) != 0) {
            insereTicketFila(f, cpf, m, getTempoEstimadoManutencao, getTipoManutencao, notificaManutencao, desalocaManutencao);
            ContabilizaTicketUsuario(lu, cpf);
        } else {
            desalocaManutencao(m);
        }
    }

    if (strcmp(tipo, "OUTROS") == 0) {
        Outros *o;
        o = lerOutros();
        
        if (comparaCPF(lu, cpf) != 0) {
            insereTicketFila(f, cpf, o, getTempoEstimadoOutros, getTipoOutros, notificaOutros, desalocaOutros);
            ContabilizaTicketUsuario(lu, cpf);
        } else {
            desalocaOutros(o);
        }
    }

    if (strcmp(tipo, "SOFTWARE") == 0) {
        Software *s; 
        s = lerSoftware();
        
        if (comparaCPF(lu, cpf) != 0) {
            insereTicketFila(f, cpf, s, getTempoEstimadoSoftware, getTipoSoftware, notificaSoftware, desalocaSoftware);
            ContabilizaTicketUsuario(lu, cpf);
        } else {
            desalocaSoftware(s);
        } 
    } 
        
}


void RealizaAcao(){
    char acao[MAX_TAM_ACAO];
    scanf("%[^\n]\n", acao);

    if (acao == "DISTRIBUI") {
        /* code */
    } 

    if (acao == "NOTIFICA") {
        /* code */
    }
    
    if (acao == "USUARIOS") {
        /* code */
    }
    
    if (acao == "TECNICOS"){
        /* code */
    }

    if (acao == "RANKING TECNICOS") {
        /* code */
    }
    
    if (acao == "RANKING USUARIOS") {
        /* code */
    }
    
    if (acao == "RELATORIO") {
        /* code */
    }
    
}