#include "pilha.c"

t_pilha converte_base (int n){
    t_pilha p;
    constroi_pilha (&p);
    while (n>1){
        push (n%2, &p);
        n = n/2;
    }
    push (n, &p);
    return p;
}

int main (){
    int aux;
    if (pop(&pilha, &aux)){

    }
    exibe_pilha (&pilha);
    while (pop(&pilha, &aux)){

    }
    exibe_pilha (&pilha)
    return 0;
}
