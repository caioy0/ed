// cachorro.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cachorro.h"

static void cachorro_falar(void *this) {
    Cachorro *c = (Cachorro *)this;
    printf("%s (Cachorro): Au au!\n", c->nome);
}

static void cachorro_comer(void *this) {
    Cachorro *c = (Cachorro *)this;
    printf("%s está comendo ração.\n", c->nome);
}

static void cachorro_destruir(void *this) {
    Cachorro *c = (Cachorro *)this;
    free(c->nome);
    free(c);
}

Cachorro* criar_cachorro(const char* nome) {
    Cachorro* c = malloc(sizeof(Cachorro));
    c->nome = strdup(nome);

    c->base.tipo = TIPO_CACHORRO;
    c->base.falar = cachorro_falar;
    c->base.comer = cachorro_comer;
    c->base.destruir = cachorro_destruir;

    return c;
}
