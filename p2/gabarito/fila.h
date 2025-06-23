#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * dados;
    int primeiro, ultimo;
    int capacidade, ocupacao;
} t_fila;

t_fila * constroi_fila (int);
int fila_cheia (t_fila *);
int fila_vazia (t_fila *);
void exibir_fila (t_fila *);
int enfileira (int , t_fila *);
int desenfileira (int *, t_fila *);
int proxima (int pos, int capacidade);
void mostra_vetor (t_fila *fila);
int lanterninha(t_fila *fila, int *temp);