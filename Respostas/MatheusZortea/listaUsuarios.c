#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "listaUsuarios.h"
#include "ticket.h"

#define MAX_NOME 100


typedef struct ListaUsuarios{
    Usuario **u;
    int qtdUsuarios;
    int capacidade;
} ListaUsuarios;


ListaUsuarios *criaListaUsuarios(){
    ListaUsuarios *lu = (ListaUsuarios*) malloc(sizeof(ListaUsuarios));
    lu->u = (Usuario**) malloc(2 * sizeof(Usuario*));
    lu->qtdUsuarios = 0;
    lu->capacidade = 2;
    return lu;
}


void insereUsuarioLista(ListaUsuarios *lu, Usuario *u){
    if (lu->capacidade == lu->qtdUsuarios){
        lu->u = (Usuario**) realloc(lu->u, (lu->capacidade + 2) * sizeof(Usuario*));
        lu->capacidade += 2;
    }
    
    lu->u[lu->qtdUsuarios] = u;
    
    lu->qtdUsuarios++;
}

void desalocaListaUsuarios(ListaUsuarios *lu){
    for (int i = 0; i < lu->qtdUsuarios; i++){
        desalocaUsuario(lu->u[i]);
    }
    free(lu->u);
    free(lu);
}

int getQtdUsuariosCadastrados(ListaUsuarios *lu){
    return lu->qtdUsuarios;
}

Usuario *getUsuarioNaLista(ListaUsuarios *lu, int i){
    return lu->u[i];
}

//retorna i se ele existir, 0 caso contrario, -1 se i=0
int comparaCPF(ListaUsuarios *lu, char *cpf){
    

    for (int i = 0; i < lu->qtdUsuarios; i++){
        if (strcmp(getCpfUsuario(lu->u[i]), cpf) == 0){
            if (i != 0){
                return i;
            } else {
                return -1;
            }                
        }
    }
    return 0;
}

void TrocaPosicaoUsuarios(ListaUsuarios *lu, int i){
    Usuario *temp = lu->u[i];
    lu->u[i] = lu->u[i+1];
    lu->u[i+1] = temp;
}

ListaUsuarios *CopiaListaUsuarios(ListaUsuarios *lu) {

    ListaUsuarios *novaLista = criaListaUsuarios();
    int qtdUsuarios = lu->qtdUsuarios;

    // Percorrer a lista original e copiar cada usuário
    for (int i = 0; i < qtdUsuarios; i++) {
        Usuario *usuarioOriginal = getUsuarioNaLista(lu, i);

         // Criar cópia da Data para evitar problemas de ponteiro
        Data *novaData = CopiaData(getNascimentoUsuario(usuarioOriginal));

        // Criar um novo usuário com os mesmos dados
        Usuario *novoUsuario = CriaUsuario(
            getNomeUsuario(usuarioOriginal),
            getCpfUsuario(usuarioOriginal),
            novaData,
            getTelefoneUsuario(usuarioOriginal),
            getGeneroUsuario(usuarioOriginal),
            getSetorUsuario(usuarioOriginal)
        );

        AtualizaQtdTickets(usuarioOriginal, novoUsuario);

        // Inserir o novo usuário na nova lista
        insereUsuarioLista(novaLista, novoUsuario);
    }

    return novaLista;
}

/*FAZ UMA COPIA DA LISTA DE USUARIOS, ORDENA ELA E IMPRIME*/
void RankingUsuario(ListaUsuarios *lu) {
    ListaUsuarios *listaOrdenada = CopiaListaUsuarios(lu);

    //bubble sort para colocar os usuario com mais tickets primeiros
    for (int i = 0; i < lu->qtdUsuarios - 1; i++){
        for (int j = 0; j < lu->qtdUsuarios - i - 1; j++){
            if (getTicketsSolicitados(listaOrdenada->u[j]) < getTicketsSolicitados(listaOrdenada->u[j+1])){
                TrocaPosicaoUsuarios(listaOrdenada, j);
            } 
            /*SE FOR IGUAL PEGA POR ORDEM ALFABETICA*/
            else if(getTicketsSolicitados(listaOrdenada->u[j]) == getTicketsSolicitados(listaOrdenada->u[j+1])){
                if (strcmp(getNomeUsuario(listaOrdenada->u[j+1]), getNomeUsuario(listaOrdenada->u[j])) < 0) {
                    TrocaPosicaoUsuarios(listaOrdenada, j);
                }
            }
        }
    }

    notificaRankingUsuarios(listaOrdenada);
}


/**
 * @brief A função notificaFila imprime todos os tickets na Fila f
 * @param f  Fila inicializada contendo zero ou mais tickets.
 */
void notificaListaUsuarios(ListaUsuarios *lu){
    printf("----- BANCO DE USUARIOS -----\n");
    for (int i = 0; i < lu->qtdUsuarios; i++){
        printf("--------------------\n");
        notificaUsuario(lu->u[i]);     
    }
    printf("----------------------------\n");
    printf("\n");
}

void notificaRankingUsuarios(ListaUsuarios *lu){
    printf("----- RANKING DE USUARIOS -----\n");
    for (int i = 0; i < lu->qtdUsuarios; i++){
        printf("--------------------\n");
        notificaUsuario(lu->u[i]);     
    }
    printf("-------------------------------\n");
    printf("\n");
}