#include "no.h"

typedef struct{
    t_no * primeiro;
    t_no * ultimo;
}t_lista;

void constroi_lista(t_lista *);
int lista_vazia(t_lista *);
void insere_inicio(int, t_lista *);
int remove_inicio(t_lista *);
void insere_fim(int, t_lista *);
int remove_fim(t_lista *);
void mostra_lista (t_lista *);
int pares(t_lista *);
int conta_pares (t_lista *, int *);
void inverter (t_lista *, t_lista *);