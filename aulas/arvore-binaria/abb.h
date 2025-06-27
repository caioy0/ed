#include "no.h"

typedef struct{
    int *raiz;
} t_abb;

void inicia_abb (t_abb *);
int abb_vazia (t_abb *);
void insere (int, t_abb *);
void insere_rec (t_no *, t_no *);
void imprime (t_abb *);
void imprime_rec (t_no *atual);
int busca (int, t_abb*);
