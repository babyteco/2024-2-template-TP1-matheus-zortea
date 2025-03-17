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

#define MAX_TAM_TIPO 20


void ComecaLeitura(){
    char cpf[MAX_TAM_CPF];
    char tipo[MAX_TAM_TIPO];

    scanf("%[^\n]\n", cpf);
    scanf("%[^\n]\n", tipo);

    if (strcmp(tipo, "MANUTENCAO") == 0) {
        Manutencao *m; 
        m = lerManutencao();
    }
        
}