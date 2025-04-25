#include "no.h"

typedef struct {
    t_no * primeiro;
    t_no * ultimo;
} t_lista;

void constroi_lista (t_lista *);
void lista_vazia (t_lista *);
int remove_inicio (t_lista *);
int insere_inicio (int, t_lista*);
void mostra_lista (t_lista *);
