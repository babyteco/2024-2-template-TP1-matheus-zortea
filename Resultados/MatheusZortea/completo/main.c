#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "usuario.h"
#include "tecnico.h"
#include "software.h"
#include "manutencao.h"
#include "outros.h"
#include "ticket.h"
#include "fila.h"
#include "listaTecnicos.h"
#include "listaUsuarios.h"

int main(){

    ListaTecnicos *lt = CriaListaTecnicos();
    ListaUsuarios *lu = CriaListasUsarios();
    Fila *f = criaFila();

    char operacao;
    scanf("%c\n", &operacao);

    while (operacao != 'F'){
        if (operacao == "T") {
            Tecnico *t = LeTecnico();
            insereTecnicoLista(lt, t);
        }
        
        if (operacao == "U") {
            Usuario *u = LeUsuario();
            insereUsuarioLista(lu, u);
        }
        
        /*if (operacao == "A") {
        }
        /*
        A (caractere indicando a abertura do ticket)
        255.942.213-22 (CPF do usuário solicitante)
        OUTROS (tipo do ticket)
        RECOLHER COBRA QUE APARECEU NA ENTRADA DO PREDIO (descrição)
        PASSARELA DE ENTRADA (local)
        5 (dificuldade estimada pelo usuário)
        
        A (caractere indicando a abertura do ticket)
        123.932.250-46 (CPF do usuário solicitante)
        MANUTENCAO (tipo do ticket)
        PORTA DE ENTRADA (nome do item)
        RUIM (estado de conservação)
        SALA 22 BLOCO B (localização)
        
        A (caractere indicando a abertura do ticket)
        524.456.852-98 (CPF do usuário solicitante)
        SOFTWARE (tipo do ticket)
        EXCEL (nome do software)
        DUVIDA (categoria da solicitação)
        2 (impacto no trabalho)
        NAO CONSIGO ORDENAR COLUNA DE DADOS (motivo da solicitação)
    */
        scanf("%c\n", &operacao);
    }
    
    


    
    return 0;
}