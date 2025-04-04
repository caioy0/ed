#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

static void pessoa_falar(void *this) {
    Pessoa *p = (Pessoa *)this;
    printf("%s (Pessoa): Oi, tenho %d anos.\n", p->nome, p->idade);
}

static void pessoa_comer(void *this) {
    Pessoa *p = (Pessoa *)this;
    printf("%s está comendo arroz e feijão.\n", p->nome);
}

static void pessoa_destruir(void *this) {
    Pessoa *p = (Pessoa *)this;
    free(p->nome);
    free(p);
}

Pessoa* criar_pessoa(const char* nome, int idade) {
    Pessoa* p = malloc(sizeof(Pessoa));
    p->nome = strdup(nome);
    p->idade = idade;

    p->base.tipo = TIPO_PESSOA;
    p->base.falar = pessoa_falar;
    p->base.comer = pessoa_comer;
    p->base.destruir = pessoa_destruir;

    return p;
}
