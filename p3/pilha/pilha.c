#include "pilha.h"

void constroi_pilha (int capacidade, t_pilha *pilha){
    pilha->dados = (int *) malloc (capacidade * sizeof(int));
    pilha->topo = 0;
    pilha->capacidade = capacidade;
}
int pilha_vazia (t_pilha *pilha){
    return !pilha->topo; // Se a pilha nao tiver um topo
    // if (pilha->topo == NULL) return 0;
}
int pilha_cheia (t_pilha *pilha){
    return pilha->topo == pilha->capacidade; // topo for igual a capacidade
}

int push (int i, t_pilha *pilha){
    if(pilha_cheia(pilha)) return 0;
    pilha->dados[pilha->topo++] = i; // 
    return 1;
}
int pop (t_pilha *pilha, int *removido){
    if(pilha_vazia(pilha)) return 0;
    *removido = pilha->dados[--pilha->topo]; //--topo-1?
    return 1; 
}

void mostra_pilha (t_pilha *pilha){
    if(pilha_vazia(pilha)) printf("Pilha vazia!\n");
    for (int i = pilha->topo-1; i >= 0; i--){ // !!! A logica invertida?
        printf("[%d]\n", pilha->dados[i]);    
    }
    printf("---------\n");
}

int remover_elementos(int n, t_pilha *pilha){
    if (pilha_vazia(pilha)) return 0;
    int temp;
    int removidos = 0;

    while (n-- > 0 && !pilha_vazia(pilha)) {
        pop(pilha, &temp);
        removidos++;
    }
    return removidos;
}
void inverter_pilha (t_pilha *pilha){
    if (pilha_vazia(pilha)) printf("Pilha vazia!\n");
    t_pilha *invertida;
    invertida = (t_pilha *) malloc(sizeof(t_pilha));
    constroi_pilha(pilha->capacidade, invertida);
    int aux;
    while (pop(pilha, &aux)){
        push(aux, invertida);
    }
    // atualizar os dados da pilha temp
    pilha->dados = invertida->dados;
    pilha->topo = invertida->topo;
    mostra_pilha(invertida);
}