#include "fila.h"
#include <time.h>

int main(){
    t_fila *fila = constroi_fila(fila);
    int a;
    srand(time(0));
    do{
        if(rand() % 2 == 0){
            enfileira(rand() % 10, fila);
        }
        else{
            desenfileira(&a, fila);
        }
        mostra_fila(fila);
        printf("\n\\\\\\\\\\\\\\\\\n");

    } while(!fila_vazia(fila));

    enfileira(1, fila);
    enfileira(4, fila);
    enfileira(7, fila);
    enfileira(2, fila);
    enfileira(9, fila);

    t_fila *pares = constroi_fila(pares);
    t_fila *impares = constroi_fila(impares);

    separa_pares_impares(fila, pares, impares);

    printf("Fila filainal: ");
    mostra_fila(fila);
    printf("\nFila de pares: ");
    mostra_fila(pares);
    printf("\nFila de ímpares: ");
    mostra_fila(impares);

    t_fila *f1 = constroi_fila(f1);
    t_fila *f2 = constroi_fila(f2);

    enfileira(1, f1);
    enfileira(2, f1);
    enfileira(3, f2);
    enfileira(4, f2);
    enfileira(5, f2);

    move_menor_para_maior(f1, f2);

    printf("\nF1: ");
    mostra_fila(f1);
    printf("\nF2: ");
    mostra_fila(f2);
    return 0;
}