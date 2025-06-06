#include "pilha.h"

t_pilha converte_base (int n) {
    t_pilha p;
    constroi_pilha (&p);
    while (n > 1) {
        push (n%2, &p);
        n = n / 2;
    }
    push (n, &p);
    return p;
}

int main () {
    t_pilha pilha, pilha2;
    constroi_pilha(&pilha);
    exibe_pilha (&pilha);
    
    
    push(10, &pilha);
    push(20, &pilha);
    push(30, &pilha);
    exibe_pilha (&pilha);
    
    int aux;
    if (pop(&pilha, &aux)) {
        printf ("%d foi desempilhado\n", aux);
    }
    else {
        printf ("pilha vazia, nao foi possivel desempilhar");
    }
    exibe_pilha (&pilha);
    
    while (pop(&pilha, &aux)) {
        printf ("%d foi desempilhado\n", aux);
    }
    exibe_pilha (&pilha);
    push(10, &pilha);
    push(20, &pilha);
    push(30, &pilha);
    exibe_pilha(&pilha);
    
    // pilha = converte_base(13);
    // exibe_pilha(&pilha);
    
    constroi_pilha(&pilha2);
    exibe_pilha(&pilha);
    exibe_pilha(&pilha2);
    push(40, &pilha2);
    push(50, &pilha2);
    push(80, &pilha2);
    intercalar(&pilha, &pilha2);
    exibe_pilha(&pilha);
    exibe_pilha(&pilha2);

    return 0;
}