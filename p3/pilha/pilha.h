#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int topo;
    int * dados;
    int capacidade;
} t_pilha;

void constroi_pilha (int, t_pilha *);
int pilha_vazia (t_pilha *);
int pilha_cheia (t_pilha *);
int push (int, t_pilha *);
int pop (t_pilha *, int *);
void mostra_pilha (t_pilha *);
int remover_elementos(int, t_pilha *);
void inverter_pilha (t_pilha *);
int fura_push (int ,t_pilha *);