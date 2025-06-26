
#include "fila.h"

int main(){
    t_fila *fila;
    fila = constroi_fila(4);
    mostrar_fila(fila);
    enfileira(10, fila); // 0 primeiro (head)
    enfileira(20, fila); // 1
    enfileira(30, fila); // 2
    enfileira(40, fila); // 3 ultimo (tail)
    mostrar_fila(fila);

    int temp;
    desenfileira(fila, &temp); // [0] (50) primeiro sai
    enfileira(50, fila); // [0] (50) novo ultimo e [1](20) passa a ser o primeiro
    printf("%d foi desenfilerado\n", temp);
    // if (enfileira (10,fila)) printf("Insert ok!\n");
    // else printf("Erro Insert!\n");
    mostrar_fila(fila);

    desenfileira(fila, &temp);
    printf("%d foi desenfilerado\n", temp);

    mostrar_fila(fila);
    
    fura_fila(10, fila);
    mostrar_fila(fila);
    
    desenfileira(fila, &temp);
    printf("%d foi desenfilerado\n", temp);
    mostrar_fila(fila);

    lanterinha(fila, &temp);
    printf("Ultimo elemento da fila: %d\n", temp);
    
    exibir_primeiro(fila, &temp);
    printf("Primeiro elemento da fila: %d\n", temp);

    enfileira(1, fila);

    separar_fila(fila);

    t_fila *f1 = constroi_fila(10);
    t_fila *f2 = constroi_fila(10);
    enfileira(1,f1);
    enfileira(2,f1);
    enfileira(3,f1);
    printf("INICIO F1: \n");
    mostrar_fila(f1);
    
    enfileira(20,f2);
    enfileira(12,f2);
    enfileira(22,f2);
    enfileira(30,f2);
    printf("INICIO F2: \n");
    mostrar_fila(f2);
    
    juntar_filas(f1,f2);
    printf("FINAL F1: \n");
    mostrar_fila(f1);

    printf("FINAL F2: \n");
    mostrar_fila(f2);

    return 0;
}