#include "fila.h"
#include <time.h>

int main (){
    t_fila * fila;
    int *pi = (int *) malloc (sizeof(int));
    fila = constroi_fila(4);

    exibir_fila(fila);
    if (enfileira (10,fila)) printf("Insert ok!\n");
    // else printf("Erro Insert!\n");

    enfileira (20,fila);
    exibir_fila(fila);

    if (desenfileira(pi, fila)) printf("%d saiu da fila\n", *pi);
    else printf("falhou! fila vazia\n");
    
    exibir_fila(fila);
    enfileira (30,fila);
    exibir_fila(fila);

    fura_fila(40, fila);
    exibir_fila(fila);
    exibir_primeiro(fila);
    exibir_ultimo(fila);

    int a;
    srand(time(0));
    do {
        if (rand()%2){
            enfileira (rand()%10, fila);
        } else{
          desenfileira(&a,fila);  
        }
        mostra_vetor(fila);
    }while (!fila_vazia(fila));
    return 0;
}
