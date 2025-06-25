#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int capacidade, ocupacao;
    int primeiro, ultimo;
}t_fila;

//int constroi_fila (int, t_fila *);
t_fila * constroi_fila (int);
int fila_vazia (t_fila *);
int fila_cheia (t_fila *);
int queue (int, t_fila *);
int remover (t_fila *, int *);
int proxima (int pos, int capacidade);
void mostrar_fila (t_fila *);