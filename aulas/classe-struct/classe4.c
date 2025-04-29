#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ====== Interface/Base: Animal ======
typedef struct Animal {
    void (*falar)(void *this);
    void (*destruir)(void *this);
} Animal;

// ====== Pessoa ======
typedef struct Pessoa {
    Animal base;
    char *nome;
    int idade;
} Pessoa;

void pessoa_falar(void *this) {
    Pessoa *p = (Pessoa *)this;
    printf("%s (Pessoa): Olá! Tenho %d anos.\n", p->nome, p->idade);
}

void pessoa_destruir(void *this) {
    Pessoa *p = (Pessoa *)this;
    free(p->nome);
    free(p);
}

Pessoa* criar_pessoa(const char *nome, int idade) {
    Pessoa *p = malloc(sizeof(Pessoa));
    p->nome = strdup(nome);
    p->idade = idade;
    p->base.falar = pessoa_falar;
    p->base.destruir = pessoa_destruir;
    return p;
}

// ====== Cachorro ======
typedef struct Cachorro {
    Animal base;
    char *nome;
} Cachorro;

void cachorro_falar(void *this) {
    Cachorro *c = (Cachorro *)this;
    printf("%s (Cachorro): Au au!\n", c->nome);
}

void cachorro_destruir(void *this) {
    Cachorro *c = (Cachorro *)this;
    free(c->nome);
    free(c);
}

Cachorro* criar_cachorro(const char *nome) {
    Cachorro *c = malloc(sizeof(Cachorro));
    c->nome = strdup(nome);
    c->base.falar = cachorro_falar;
    c->base.destruir = cachorro_destruir;
    return c;
}

// ====== Gato ======
typedef struct Gato {
    Animal base;
    char *nome;
} Gato;

void gato_falar(void *this) {
    Gato *g = (Gato *)this;
    printf("%s (Gato): Miau!\n", g->nome);
}

void gato_destruir(void *this) {
    Gato *g = (Gato *)this;
    free(g->nome);
    free(g);
}

Gato* criar_gato(const char *nome) {
    Gato *g = malloc(sizeof(Gato));
    g->nome = strdup(nome);
    g->base.falar = gato_falar;
    g->base.destruir = gato_destruir;
    return g;
}

// ====== Usando todos os "animais" de forma polimórfica ======
int main() {
    // Vetor de animais genéricos (base + ponteiro pra objeto real)
    Animal *animais[3];
    void *objetos[3]; // guarda o ponteiro real para cast/destruição

    objetos[0] = criar_pessoa("João", 30);
    animais[0] = &((Pessoa*)objetos[0])->base;

    objetos[1] = criar_cachorro("Rex");
    animais[1] = &((Cachorro*)objetos[1])->base;

    objetos[2] = criar_gato("Mimi");
    animais[2] = &((Gato*)objetos[2])->base;

    // Polimorfismo: todos "falam"
    for (int i = 0; i < 3; i++) {
        animais[i]->falar(objetos[i]);
    }

    // Libera tudo com destrutor
    for (int i = 0; i < 3; i++) {
        animais[i]->destruir(objetos[i]);
    }

    return 0;
}
