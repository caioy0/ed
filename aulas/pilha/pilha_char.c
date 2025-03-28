#include "pilha_char.h"

void constroi_pilha(int capacidade, t_pilha_char *p){
    p -> dados = (char *) malloc (capacidade);
    p -> topo = 0;
    p -> capacidade = capacidade;
}

int push(char i, t_pilha_char *p){
    if (pilha_cheia(p)) return 0;
    p -> dados[p->topo++] = i;
    return 1;
}

int pop (t_pilha_char *p, char *removido){
    if (pilha_vazia(p)) return 0;
    *removido = p->dados[--p->topo];
    return 1;
}

int pilha_vazia (t_pilha_char *p){
    return !p -> topo;
}

int pilha_cheia (t_pilha_char *p){
    return p-> topo == p -> capacidade;
}

void exibe_pilha (t_pilha_char *p){
   if (pilha_vazia(p)) printf("pilha vazia\n");
   else{
       for (int i=p -> topo-1; i>=0; i--){
            printf("%c\n", p->dados[i]);
       }
   }
   printf("--------------------\n");
}

void inverter_pilha (t_pilha_char *p){
    t_pilha_char *invertida;
    invertida = (t_pilha_char *) malloc(sizeof(t_pilha_char));
    constroi_pilha (p -> capacidade, invertida);
    char aux;
    while(pop(p,&aux)){
        push(aux, invertida);
    }
    printf("p->dados antes: %p\n", p->dados);
    printf("Invertida->dados: %p\n", invertida->dados);
    exibe_pilha(invertida);
    p->dados = invertida -> dados;
    printf("p->dados invertidos: %p\n");
}
