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
int anterior (int, int);
void mostra_vetor (t_fila *fila);
int fura_fila (int, t_fila *);
//int limpa_fila (int i, t_fila *fila);
void exibir_primeiro (t_fila *);
void exibir_ultimo (t_fila *);