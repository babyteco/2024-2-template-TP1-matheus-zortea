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



void RealizaAcao(Fila *f, ListaUsuarios *lu, ListaTecnicos *lt){
    char acao[MAX_TAM_ACAO];
    scanf("%[^\n]\n", acao);

    if (strcmp(acao, "DISTRIBUI") == 0) {
        distribuiTicketsFila(f, lt);
    } 
    
    if (strcmp(acao, "NOTIFICA") == 0) {
        printf("----- FILA DE TICKETS -----\n");
        notificaFila(f);
        printf("---------------------------\n");
        printf("\n");
    }
    
    if (strcmp(acao, "USUARIOS") == 0) {
        notificaListaUsuarios(lu);
    }
    
    if (strcmp(acao, "TECNICOS") == 0){
        notificaListaTecnicos(lt);
    }
    
    if (strcmp(acao, "RANKING TECNICOS") == 0) {
        RankingTecnico(lt);
    }
    
    if (strcmp(acao, "RANKING USUARIOS") == 0) {
        RankingUsuario(lu);
    }
    
    if (strcmp(acao, "RELATORIO") == 0) {
        GeraRelatorio(f, lt, lu);
    }   
}

void distribuiTicketsFila(Fila *f, ListaTecnicos *lt){

    int qtdTickets = getQtdTicketsNaFila(f);
    int qtdTecnicos = getQtdTecnicosCadastrados(lt);
    int indiceTecnico = 0;
        
    for (int i = 0; i < qtdTickets; i++) {

        Ticket *ticket = getTicketNaFila(f, i);

        if (getStatusTicket(ticket) == 'F') {

            continue;
        }
        
        int encontrouTecnico = 0;
        
        for (int j = 0; j < qtdTecnicos; j++) {

            int idx = (indiceTecnico + j) % qtdTecnicos;

            Tecnico *tecnico = getTecnicoNaLista(lt, idx);
        
            //Se o tecnico for do mesmo tipo do ticket
            if ((getTipoTicket(ticket) == 'S' && strcmp(getAtuacaoTecnico(tecnico), "TI") == 0) ||
                ((getTipoTicket(ticket) != 'S') && strcmp(getAtuacaoTecnico(tecnico), "TI") != 0)) {
    
                //se o tecnico tiver tempo para o ticket    
                if (getTempoEstimadoTicket(ticket) <= getDispTempoTecnico(tecnico)) {
                       
                    int tempoTicket = getTempoEstimadoTicket(ticket);
                    
                    modificaHorasTecnico(tecnico, tempoTicket);
                    finalizaTicket(ticket);
                    indiceTecnico = (idx + 1) % qtdTecnicos;
                    encontrouTecnico = 1;
                    break;
                }
            }
        }
    
        
        if (encontrouTecnico == 0) {
            continue;
        }
    }
}

void GeraRelatorio(Fila *f, ListaTecnicos *lt, ListaUsuarios *lu){
    int TicsAbertos = getQtdTicketsPorStatusNaFila(f, 'A');
    int TicsFechados = getQtdTicketsPorStatusNaFila(f, 'F');
    int mediaIdadeUsuarios = MediaIdadeUsuarios(lu);
    int mediaIdadeTecnicos = MediaIdadeTecnicos(lt);
    int mediaTempoTrabalhado = MediaTempoTrabalhadoTecnicos(lt);

    printf("----- RELATORIO GERAL -----\n");
    printf("- Qtd tickets: %d\n", getQtdTicketsNaFila(f));
    printf("- Qtd tickets (A): %d\n", TicsAbertos);
    printf("- Qtd tickets (F): %d\n", TicsFechados);
    printf("- Qtd usuarios: %d\n", getQtdUsuariosCadastrados(lu));
    printf("- Md idade usuarios: %d\n", mediaIdadeUsuarios);
    printf("- Qtd tecnicos: %d\n", getQtdTecnicosCadastrados(lt));
    printf("- Md idade tecnicos: %d\n", mediaIdadeTecnicos);
    printf("- Md trabalho tecnicos: %d\n", mediaTempoTrabalhado);
    printf("---------------------------\n\n");
}

//botar no arquivo ticket
void LeCadastraTicket(Fila *f, ListaUsuarios *lu){
    char cpf[MAX_TAM_CPF];
    char tipo[MAX_TAM_TIPO];

    scanf("%[^\n]\n", cpf);
    scanf("%[^\n]\n", tipo);

    int flag = comparaCPF(lu, cpf);

    if (strcmp(tipo, "MANUTENCAO") == 0) {
        //passar o setor para o lemanutencao, para ele calcular as horas estimadas
        Manutencao *m;

        if ((flag != -1) && (flag != 0)) {
            m = lerManutencao(getSetorUsuario(getUsuarioNaLista(lu, flag)));
            insereTicketFila(f, cpf, m, getTempoEstimadoManutencao, getTipoManutencao, notificaManutencao, desalocaManutencao);
            AcrescentaTicketUsuario(getUsuarioNaLista(lu, flag));
        } else  if (flag == -1){
            m = lerManutencao(getSetorUsuario(getUsuarioNaLista(lu, 0)));
            insereTicketFila(f, cpf, m, getTempoEstimadoManutencao, getTipoManutencao, notificaManutencao, desalocaManutencao);
            AcrescentaTicketUsuario(getUsuarioNaLista(lu, 0));
        } else if(flag == 0){
            m = lerManutencao(getSetorUsuario(getUsuarioNaLista(lu, 0)));
            desalocaManutencao(m);
        }

    }

    if (strcmp(tipo, "OUTROS") == 0) {  
        Outros *o = lerOutros();
        
        if (flag != 0) {
            insereTicketFila(f, cpf, o, getTempoEstimadoOutros, getTipoOutros, notificaOutros, desalocaOutros);
            if(flag == -1){
                AcrescentaTicketUsuario(getUsuarioNaLista(lu, 0));
            } else {
                AcrescentaTicketUsuario(getUsuarioNaLista(lu, flag));
            }
        } else {
            desalocaOutros(o);
        }
    }

    if (strcmp(tipo, "SOFTWARE") == 0) {

        Software *s = lerSoftware();
        setTempoEstimadoSoftware(s);
        if (flag != 0) {
            insereTicketFila(f, cpf, s, getTempoEstimadoSoftware, getTipoSoftware, notificaSoftware, desalocaSoftware);
            if(flag == -1){
                AcrescentaTicketUsuario(getUsuarioNaLista(lu, 0));
            } else {
                AcrescentaTicketUsuario(getUsuarioNaLista(lu, flag));
            }
        } else {
            desalocaSoftware(s);
        } 
    } 
}