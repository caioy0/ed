// gato.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gato.h"

static void gato_falar(void *this) {
    Gato *g = (Gato *)this;
    printf("%s (Gato): Miau!\n", g->nome);
}

static void gato_comer(void *this) {
    Gato *g = (Gato *)this;
    printf("%s está comendo atum.\n", g->nome);
}

static void gato_destruir(void *this) {
    Gato *g = (Gato *)this;
    free(g->nome);
    free(g);
}

Gato* criar_gato(const char* nome) {
    Gato* g = malloc(sizeof(Gato));
    g->nome = strdup(nome);

    g->base.tipo = TIPO_GATO;
    g->base.falar = gato_falar;
    g->base.comer = gato_comer;
    g->base.destruir = gato_destruir;

    return g;
}
