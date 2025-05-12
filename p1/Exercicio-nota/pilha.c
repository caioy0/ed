#include "pilha.h"

void constroi_pilha(int capacidade, t_pilha *p){
    p -> dados = (int *) malloc (capacidade * sizeof(int));
    p -> topo = 0;
    p -> capacidade = capacidade;
}

int push(int i, t_pilha *p){
    if (pilha_cheia(p)) return 0;
    p -> dados[p->topo++] = i;
    return 1;
}

int pop (t_pilha *p, int *removido){
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
   if (pilha_vazia(p)) printf("pilha vazia\n");
   else{
       for (int i=p -> topo-1; i>=0; i--){
            printf("%d\n", p->dados[i]);
       }
   }
   printf("--------------------\n");
}

void inverter_pilha (t_pilha *p){
    t_pilha *invertida;
    invertida = (t_pilha *) malloc(sizeof(t_pilha));
    constroi_pilha (p -> capacidade, invertida);
    int aux;
    while(pop(p,&aux)){
        push(aux, invertida);
    }
    printf("p->dados antes: %p\n", p->dados);
    printf("Invertida->dados: %p\n", invertida->dados);
    exibe_pilha(invertida);
    p->dados = invertida -> dados;
}

