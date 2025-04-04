#include "pilha.h"

int main(){
    t_pilha pilha;
    constroi_pilha(10, &pilha);
    exibe_pilha(&pilha);
    
    push(10, &pilha);
    push(20, &pilha);
    push(30, &pilha);
    if (push (10, &pilha)){
        printf("deu certo\n");
    }else{
        printf("pilha cheia nao foi possivel empilhar\n");
    }
    
    exibe_pilha(&pilha);

    int aux;
    pop (&pilha, &aux);
    if (pop(&pilha, &aux)){
        printf("%d foi desempilhado", aux);
    }else{
        printf("pilha vazia, nao foi possivle desempilhar");
    }
    exibe_pilha(&pilha);

    int i= 1;
    while (push(i++, &pilha)){
        exibe_pilha(&pilha);
    }

    while (pop(&pilha, &aux)){
        printf("%d, foi desempilhado\n", aux);
    }

    push (10, &pilha);
    inverter_pilha(&pilha);
    exibe_pilha(&pilha);

    return 0;
}
