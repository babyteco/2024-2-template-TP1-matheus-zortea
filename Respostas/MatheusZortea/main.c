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
#include "gerencia.h"


int main(){

    ListaTecnicos *lt = criaListaTecnicos();
    ListaUsuarios *lu = criaListaUsuarios();
    Fila *f = criaFila();

    char operacao;
    scanf("%c\n", &operacao);

    while (operacao != 'F'){
        
        if (operacao == 'T') {
            Tecnico *t = LeTecnico();
            insereTecnicoLista(lt, t);
        }
        
        if (operacao == 'U') {
            printf("entrou para ler o usuario namoral\n");
            Usuario *u = LeUsuario();
            printf("USUARIO ANTES DE ENTRAR NA LISTA:\n");
            notificaUsuario(u);
            insereUsuarioLista(lu, u);
            printf("USUARIO DEPOIS DE ENTRAR NA LISTA:\n");
            notificaUsuario(u);
        }
        
        if (operacao == 'A') {
            LeCadastraTicket(f, lu);
        }

        if (operacao == 'E') {
            RealizaAcao(f);
        }
        
        scanf("%c\n", &operacao);
    }
    
    


    
    return 0;
}