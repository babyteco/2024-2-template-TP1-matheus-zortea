#ifndef _GERENCIA_H
#define _GERENCIA_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaUsuarios.h"
#include "data.h"
#include "ticket.h"
#include "fila.h"
#include "manutencao.h"
#include "outros.h"
#include "software.h"

#define MAX_TAM_TIPO 20

Ticket *LeCadastraTicket(Fila *f, ListaUsuarios *lu);

#endif