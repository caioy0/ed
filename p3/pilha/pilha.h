#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int topo;
    int dado;
} t_pilha;

int constroi_pilha (t_pilha *);
void push ();
void pop ();
void mostra_pilha ();