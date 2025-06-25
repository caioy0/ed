#include "fila.h"

// int constroi_fila (int i, t_fila *fila){
//     fila = (t_fila *) malloc (sizeof(t_fila));
//     fila->capacidade = capacidade;
//     fila->primeiro = 0;
//     fila->ultimo = 0;
//     fila->primeiro = 0;
//     fila->ocupacao = 0;
//     fila->dados = (int *) malloc (capacidade * sizeof(int));
// }

t_fila *constroi_fila (int capacidade){
    t_fila *fila = (t_fila *) malloc (sizeof(t_fila));
    fila->capacidade = capacidade;
    fila->primeiro = 0;
    fila->ultimo = 0;
    fila->ocupacao = 0;
    fila->dados = (int *) malloc (capacidade * sizeof(int));
   return fila; 
}

int fila_vazia (t_fila *fila){
    return fila->ocupacao == 0;
}

int fila_cheia (t_fila *fila){
    return fila->ocupacao = fila->capacidade; 
}

int queue (int i, t_fila *fila){
    if (fila_cheia(fila)) return 0;
    i = fila->dados[fila->ultimo];
    fila->ultimo = proxima(fila->ultimo, fila->capacidade);
    fila->ocupacao++;
    return 1;
}
int remover (t_fila *fila, int *i){
    if (fila_vazia(fila)) return 0;
    *i = fila->dados[fila->primeiro];
    fila->primeiro = proxima(fila->primeiro, fila->capacidade);
    fila->ocupacao--;
    return 1;
}
int proxima(int pos, int capacidade){
    return (pos+1) % capacidade;
}
void mostrar_fila (t_fila *fila){
    if (fila_vazia(fila)) printf("Fila vazia");
    int i = fila->primeiro;
    do {
        printf("Fila: %d\n", fila->dados[i]);
        i = proxima(i, fila->capacidade);
    } while (i!=fila->ultimo);
    printf("\n");
}