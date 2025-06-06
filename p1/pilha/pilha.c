#include "pilha.h"

// Inverter pilha

int pop (t_pilha *p, int *removido){
    if (pilha_vazia(p)) return 0; // da onde saiu pilha_vazia?
    *removido = p->dados[--p->topo]; // pilha p aponta para os dados da struct pilha
                                    // --p diminuindo os dados, depois aponta para o topo?
    return 1;
}

int push(int i, t_pilha *p){
    if (pilha_cheia(p)) return 0;
    p -> dados[p->topo++] = i; // IGUAL A I???? WTFFFFF
    return 1;
}

void constroi_pilha(int capacidade, t_pilha *p){
    p -> dados = (int *) malloc (capacidade * sizeof(int)); // dados em int
    p -> topo = 0; // Topo comeca em 0 pq?
    p -> capacidade = capacidade; // ok p -> == this.
}

int pilha_vazia (t_pilha *p){
    return !p -> topo; // Se p->topo es zero
}

int pilha_cheia (t_pilha *p){
    return p-> topo == p -> capacidade;
}

void exibe_pilha (t_pilha *p){
    if (pilha_vazia(p)) printf("pilha vazia\n");
    else{
        for (int i=p -> topo-1; i>=0; i--){
             printf("%d\n", p->dados[i]);
        }
    }
    printf("--------------------\n");
 }

void inverter_pilha (t_pilha *p){ 
    t_pilha *invertida; // Porque tem uma *?, Aqui criamos uma instancia de pilha
    // invertida é um ponteiro para uma pilha. Ou seja, 
    // ela vai apontar para uma struct t_pilha que está alocada dinamicamente
    invertida = (t_pilha *) malloc(sizeof(t_pilha)); // Alocacao dinamica de 
    // uma pilha 
    constroi_pilha (p -> capacidade, invertida); // Toda pilha tem q ser construida
    int aux;
    while(pop(p,&aux)){
        push(aux, invertida);
    }
    p->dados = invertida -> dados; // a struct antiga aponta para dados que eh
    // igual a invertida dados
    p->topo = invertida->topo;
    printf("p->dados antes: %d\n", (void *) p -> dados);
    printf("Invertida->dados: %d\n", (void *) invertida->dados);
    exibe_pilha(invertida);
}
