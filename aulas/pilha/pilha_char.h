#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int * dados;
    int topo;
    int capacidade;
} t_pilha_char;

void constroi_pilha(int capacidade, t_pilha_char *p);
int push(int i, t_pilha_char *p);
int pop (t_pilha_char *p, int *removido);
int pilha_vazia (t_pilha_char *p);
int pilha_cheia (t_pilha_char *p);
void exibe_pilha (t_pilha_char *p);
void inverter_pilha (t_pilha_char *p);
