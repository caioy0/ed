
#include "fila.h"

int main(){
    t_fila *fila;
    fila = constroi_fila(4);
    mostrar_fila(fila);
    queue(10, fila);
    mostrar_fila(fila);
    return 0;
}