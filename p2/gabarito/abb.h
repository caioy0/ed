#include "no.h"

typedef struct{
    t_no *raiz;
} t_abb;

void inicia_abb(t_abb *);
int abb_vazia(t_abb *);
void insere(int, t_abb *);
void insere_rec(t_no *, t_no *);
void imprime(t_abb *);
void imprime_rec(t_no *);
int busca(int, t_abb *);
int busca_rec(int, t_no *);
int conta_x (int, t_abb *);
int conta_x_rec (int, t_no *atual);