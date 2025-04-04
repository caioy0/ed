// cachorro.h
#ifndef CACHORRO_H
#define CACHORRO_H

#include "oo.h"

typedef struct Cachorro {
    Objeto base;
    char *nome;
} Cachorro;

Cachorro* criar_cachorro(const char* nome);

#endif
