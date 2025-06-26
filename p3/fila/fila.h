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
int enfileira (int, t_fila *);
int desenfileira (t_fila *, int *);
int proxima (int, int);
void mostrar_fila (t_fila *);
int fura_fila (int, t_fila *);
int lanterinha (t_fila *, int *);
int exibir_primeiro(t_fila *, int *);
int separar_fila(t_fila *);
int juntar_filas (t_fila *, t_fila *);