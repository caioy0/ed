#include <stdio.h>
#include "abb.h"
#include "fila.h"
#include "pilha.h"

int main(){
    // EX1
    t_pilha minha_pilha;
    int temp;
    constroi_pilha(&minha_pilha);
    push(10, &minha_pilha);
    push(20, &minha_pilha);
    push(30, &minha_pilha);
    pop (&minha_pilha, &temp);
    printf("Ex1-A) ");
    exibe_pilha(&minha_pilha);
    printf("\n");
    
    // implemente uma nova func top 
    // que retorna o valor armazenado no topo da pilha
    top(&minha_pilha, &temp);
    printf("EX1-B) ");
    printf("%d\n", temp);
    printf("\n");
    
    // EX2
    t_fila *fila = constroi_fila(5);
    enfileira(10, fila);
    enfileira(20, fila);
    enfileira(30, fila);
    desenfileira(&temp, fila);
    enfileira(40, fila);
    enfileira(50, fila);
    enfileira(60, fila);
    printf("EX2-A) ");
    exibir_fila(fila);
    
    // Retorna o valor armazenado na ultima posicao da fila
    printf("EX2-B) ");
    lanterninha(fila, &temp);
    printf("%d\n", temp);
    printf("EX2-C) Nao funciona, pois nem sempre primeiro\
    \nes menor que ultimo, estrutura do vetor es circular \n\n");

    //EX3
    t_abb abb;
    inicia_abb (&abb);
    if (abb_vazia (&abb)) printf("arvore inicializada e vazia\n");
    else printf("incializda, nao esta vazia\n");

    for (int i=1; i<=12; i++){
        int n = rand () % 20;
        printf("Inserindo: %d \n", n);
        insere (n, &abb);
    }
    imprime (&abb);
    
    if(busca(10, &abb)) printf("\n10 esta na arvore");
    else printf("\n10 nao esta na arvore");
    printf("\n");

    int contador;
    int num = 3;
    contador = conta_x(num, &abb);  // x precisa ser um valor válido
    printf("O valor %d aparece %d vez na arvore\n", num, contador);

    return 0;
}