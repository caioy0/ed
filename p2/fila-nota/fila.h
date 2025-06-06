#include <stdio.h>
#include "no.h"

typedef struct {
    int * dados;
    int primeiro, ultimo;
    int capacidade, ocupacao;
    t_no * primeiro;
    t_no * ultimo;
} t_fila;

t_fila * constroi_fila (int);
int fila_cheia (t_fila *);
int fila_vazia (t_fila *);
void exibir_fila (t_fila *);
int enfileira (int , t_fila *);
int desenfileira (int *, t_fila *);
int proxima (int pos, int capacidade);
void mostra_vetor (t_fila *fila);
void mostra_fila(t_fila *);
void exibe_primeiro (t_fila *);
int devolve_primeiro (t_fila *);
void exibe_ultimo (t_fila *);
int devolve_ultimo (t_fila *);
void limpa_fila (t_fila *);