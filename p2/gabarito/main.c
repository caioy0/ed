#include <stdio.h>
#include "abb.c"
#include "fila.c"
#include "pilha.c"

int main(){
    // EX1
    t_pilha minha_pilha;
    int temp;
    constori_pilha(&minha_pilha);
    push(10, &minha_pilha);
    push(20, &minha_pilha);
    push(30, &minha_pilha);
    pop (&minha_pilha, &temp);
    exibe_pilha(&minha_pilha);

    // implemente uma nova func top 
    // que retorna o valor armazenado no topo da pilha
    top(&minha_pilha, &temp);

    // EX2
    t_fila *fila = constroi_fila(5);
    enfileira(10, fila);
    enfileira(20, fila);
    enfileira(30, fila);
    desenfileira(&temp, fila);
    enfileira(40, fila);
    enfileira(50, fila);
    enfileira(60, fila);
    mostra_fila(fila);

    // Retorna o valor armazenado na ultima posicao da fila
    lanterninha(fila, &temp);

    // Resposta B) Nao funciona, pois nem sempre primeiro
    // Menor que ultimo, estrutura do vetor eh circular

    // EX3
    t_abb abb;
    inicia_abb (&abb);
    if (abb_vazia (&abb)) printf("arvore inicializada vazia\n");
    else printf("incializda, nao esta vazia\n");

    for (int i=1; i<=12; i++){
        int n = rand () % 20;
        printf("%d", n);
        insere (n, &abb);
    }
    imprime (&abb);
    int x;
    conta_x(x, &abb);

    return 0;
}