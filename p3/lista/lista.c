#include "lista.h"
#include <stdio.h>

void constroi_lista(t_lista *lista){
    lista->primeiro = lista->ultimo = NULL;
}
int lista_vazia(t_lista *lista){
    return !lista->primeiro;
}
void insere_inicio(int i, t_lista *lista){
    t_no * novo = constroi_no(i);
    if(lista_vazia(lista)) lista->ultimo = novo;
    else novo->proximo = lista->primeiro;
    lista->primeiro = novo;
}
int remove_inicio(t_lista *lista){
    if (lista_vazia(lista)) return -1;
}
void insere_fim(int i, t_lista *lista);
int remove_fim(t_lista *lista);