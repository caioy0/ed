#include "pilha.h"

int main (){
    t_pilha pilha;
    constroi_pilha(5, &pilha);
    mostra_pilha(&pilha);
    push(10, &pilha);
    push(20, &pilha);
    push(30, &pilha);
    mostra_pilha(&pilha);

    int temp;
    pop(&pilha, &temp);
    push(40, &pilha);
    printf("\n%d foi desempilhado\n", temp);
    mostra_pilha(&pilha);

    printf("Pilha invertida!\n");
    inverter_pilha(&pilha);
    
    int cont = 2;
    remover_elementos(cont, &pilha);
    printf("Foram desempilhados %d elementos\n", cont);
    mostra_pilha(&pilha);

    return 0;
}