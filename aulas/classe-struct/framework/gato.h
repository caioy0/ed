// gato.h
#ifndef GATO_H
#define GATO_H

#include "oo.h"

typedef struct Gato {
    Objeto base;
    char *nome;
} Gato;

Gato* criar_gato(const char* nome);

#endif
