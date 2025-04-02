#include "pilha.h"

int pop (t_pilha *p, int *removido){
    if (pilha_vazia(p)) return 0; // da onde saiu pilha_vazia?
    *removido = p->dados[--p->topo]; // pilha p aponta para os dados da struct pilha
                                    // --p diminuindo os dados, depois aponta para o topo?
    return 1;
}

int push(int i, t_pilha *p){
    if (pilha_cheia(p)) return 0;
    p -> dados[p->topo++] = i;
    return 1;
}

int main (){
    int num;
    printf("Insira os dados para a pilha: ");
    scanf("%d",&num);
    return 0;
}