#include "pilha.h"

int constroi_pilha (t_pilha *pilha){
    pilha->topo
}
int lista_vazia (t_pilha *lista){
    return !lista->topo;
}
void push (int i, t_pilha *lista){
    t_no * novo = constroi_no(i);
    if (!lista_vazia(lista))
        novo->prox = lista->topo;
    pilha->topo = novo;
}
int pop(t_pilha *lista){
    if (lista_vazia(lista)) return -1;
    int temp = lista->topo->info;
    t_no * aux = lista->topo;
    lista->topo = lista->topo->prox;
}
void exibe_pilha (t_pilha * pilha){
    if (lista_vazia(pilha)) printf ("pilha vazia\n")
    else {
        t_no * runner = pilha->topo;
        while (runner != NULL) 
    }
}
