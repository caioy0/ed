#include "pilha.h"

void constroi_pilha (t_pilha *pilha) {
    pilha->topo = NULL;
}
int pilha_vazia (t_pilha *pilha) {
    return !pilha->topo;
}
void push (int i, t_pilha *pilha) {
    t_no * novo = constroi_no(i);
    if (!pilha_vazia(pilha))
        novo->prox = pilha->topo;
    pilha->topo = novo;
}
int pop (t_pilha *pilha, int * temp) {
    if (pilha_vazia(pilha)) return 0;
    *temp = pilha->topo->info;
    t_no * aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(aux);
    return 1;
}
void exibe_pilha (t_pilha * pilha) {
    if (pilha_vazia(pilha))
        printf ("pilha vazia\n");
    else {
        t_no * runner = pilha->topo;
        while (runner != NULL) {
            printf ("[%d] -> ", runner->info);
            runner = runner->prox;
        }
        printf ("\\\\\n");
    }
}
