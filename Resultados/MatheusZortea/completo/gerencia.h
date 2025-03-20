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


void LeCadastraTicket(Fila *f, ListaUsuarios *lu);

void RealizaAcao(Fila *f, ListaUsuarios *lu, ListaTecnicos *lt);

void GeraRelatorio(Fila *f, ListaTecnicos *lt, ListaUsuarios *lu);

void distribuiTicketsFila(Fila *f, ListaTecnicos *lt);

#endif