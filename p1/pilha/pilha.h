#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int * dados; // Por que tem uma estrela? Resposta: Ele es um vetor dinamico
    // entao precisamos utilizar: (int *) malloc (sizeof(int));
    int topo; // Topo esta no ultimo slot?
    int capacidade;
} t_pilha;

void constroi_pilha(int capacidade, t_pilha *p); // *p esta declarado esse p????
int push(int i, t_pilha *p); // Esse *p, referencia para struct.
int pop (t_pilha *p, int *removido); // *referencia para remover o dado
int pilha_vazia (t_pilha *p);
int pilha_cheia (t_pilha *p);
void exibe_pilha (t_pilha *p);
void inverter_pilha (t_pilha *p);