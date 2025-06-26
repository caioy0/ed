#include "lista.h"
#include <stdio.h>

void constroi_lista(t_lista *lista);
int lista_vazia(t_lista *lista);
void insere_inicio(int i, t_lista *lista);
int remove_inicio(t_lista *lista);
void insere_fim(int i, t_lista *lista);
int remove_fim(t_lista *lista);