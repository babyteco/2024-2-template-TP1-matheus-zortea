#ifndef _data
#define _data


typedef struct Data Data;


/*
Inicializa uma data alocando memória para ela
retorna o ponteiro para a data inicializada
*/
Data* InicializaData();

/*
Le uma data da entrada padrão
Retorna um ponteiro para data
*/
Data* LeData();

/*
Calcula qual de duas datas e mais velha
Retorna 1 se d1 for mais antiga ou 2 se d2 for mais antiga
*/
int DiferencaDatas(Data *d1, Data *d2);

/*
Imprime a data especificada
*/
void ImprimeData(Data *d);

#endif