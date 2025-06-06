#include "fila.c"
#include "fila.h"
#include "exercicios.c"
#include <stdio.h>

int main (){
    t_fila *fila = constroi_fila(fila);
    enfileira(2, fila);
    enfileira(3, fila);
    enfileira(4, fila);
    enfileira(5, fila);
    enfileira(6, fila);
    mostra_fila(fila);
    limpa_fila(fila);
    mostra_fila(fila);  // Deve mostrar: 3 5
    return 0;
}