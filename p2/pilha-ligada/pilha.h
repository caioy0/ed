#include <stdio.h>
#include "no.h"

typedef struct {
    t_no * topo;
} t_pilha;

void constroi_pilha (t_pilha *);
int pilha_vazia (t_pilha *);
void push (int, t_pilha *);
int pop (t_pilha *, int *);
void exibe_pilha (t_pilha *);
int limpa_fila (t_pilha *);
//int busca_elemento (t_pilha *, int*);
int conta_ocorrencias (t_pilha *, int);
void oredenar_crescente (t_pilha *);
void inverter (t_pilha *);
void intercalar (t_pilha *, t_pilha *);