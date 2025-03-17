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
        
        if (operacao == 'T') {
            Tecnico *t = LeTecnico();
            insereTecnicoLista(lt, t);
        }
        
        if (operacao == 'U') {
            Usuario *u = LeUsuario();
            insereUsuarioLista(lu, u);
        }
        
        if (operacao == 'A') {
            LeCadastraTicket(f, lu);
        }

        if (operacao == 'E') {
           char acao[MAX_TAM_ACAO];
           scanf("%[^\n]\n", acao);
        }
        
        scanf("%c\n", &operacao);
    }
    
    


    
    return 0;
}