#ifndef PESSOA_H
#define PESSOA_H

#include "oo.h"

typedef struct Pessoa {
    Objeto base;
    char *nome;
    int idade;
} Pessoa;

Pessoa* criar_pessoa(const char* nome, int idade);

#endif
