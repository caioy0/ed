#include "fila.h"
#include <time.h>

int main (){
    int a;
    t_fila *fila;
    int *pi = (int *) malloc (sizeof(int));
    fila = constroi_fila(8);
    srand(time(0));
    do {
        if (rand() % 2){
            enfileira (rand()%10, fila);
        } else{
          desenfileira(&a,fila);  
        }
        mostra_vetor(fila);
    }while (!fila_vazia(fila));
    return 0; 
}
