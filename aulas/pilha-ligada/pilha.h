#include "no.h"

typedef struct {
    t_no * primeiro;
    t_no * ultimo;
} t_pilha;

void constroi_pilha (t_pilha *);
int pilha_vazia (t_pilha *);