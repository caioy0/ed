#include "pilha.h"
#include <stdio.h>

void constroi_pilha(int capacidade, t_pilha *p){
    p -> dados = (int *) malloc (capaciade * sizeof(int));
    p -> topo = 0;
    p -> capacidade = capacidade;
}

void push(int i, t_pilha *p){
    if (pilha_cheia(p)) return 0;
    p -> dados[p->topo++] = i;
    return 1;
}

int pop (t_pilha *p){
    if (pilha_vazia(p)) return 0;
    *removido = p->dados[--p->topo];
    return 1;
}

int pilha_vazia (t_pilha *p){
    return !p -> topo;
}

int pilha_cheia (t_pilha *p){
    return p-> topo == p -> capacidade;
}

void exibe_pilha (t_pilha *p){
    
}

int main(){
    
    return 0;
}
