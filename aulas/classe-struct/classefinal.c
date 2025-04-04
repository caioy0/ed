#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===== Enum para RTTI (identificação de tipo) =====
typedef enum {
    TIPO_PESSOA,
    TIPO_CACHORRO,
    TIPO_GATO
} TipoAnimal;

// ===== Classe base: Animal =====
typedef struct Animal {
    TipoAnimal tipo;
    void (*falar)(void *this);
    void (*destruir)(void *this);
} Animal;

// ===== Subclasse: Pessoa =====
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
    p->base.tipo = TIPO_PESSOA;
    p->base.falar = pessoa_falar;
    p->base.destruir = pessoa_destruir;
    return p;
}

// ===== Subclasse: Cachorro =====
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
    c->base.tipo = TIPO_CACHORRO;
    c->base.falar = cachorro_falar;
    c->base.destruir = cachorro_destruir;
    return c;
}

// ===== Subclasse: Gato =====
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
    g->base.tipo = TIPO_GATO;
    g->base.falar = gato_falar;
    g->base.destruir = gato_destruir;
    return g;
}

// ===== Fábrica de animais genéricos =====
void* criar_animal_generico(const char* tipo, const char* nome, int idade) {
    if (strcmp(tipo, "pessoa") == 0) {
        return criar_pessoa(nome, idade);
    } else if (strcmp(tipo, "cachorro") == 0) {
        return criar_cachorro(nome);
    } else if (strcmp(tipo, "gato") == 0) {
        return criar_gato(nome);
    } else {
        printf("Tipo de animal '%s' desconhecido.\n", tipo);
        return NULL;
    }
}

// ===== RTTI: identificar o tipo do animal =====
void identificar_animal(Animal* a) {
    switch (a->tipo) {
        case TIPO_PESSOA:   printf("Identificado como Pessoa\n"); break;
        case TIPO_CACHORRO: printf("Identificado como Cachorro\n"); break;
        case TIPO_GATO:     printf("Identificado como Gato\n"); break;
        default:            printf("Tipo desconhecido\n"); break;
    }
}

// ===== Main =====
int main() {
    // Cria objetos via fábrica
    void* obj1 = criar_animal_generico("pessoa", "Alice", 35);
    void* obj2 = criar_animal_generico("cachorro", "Bidu", 0);
    void* obj3 = criar_animal_generico("gato", "Mingau", 0);

    // Referências genéricas
    Animal* animais[] = {
        &((Pessoa*)obj1)->base,
        &((Cachorro*)obj2)->base,
        &((Gato*)obj3)->base
    };

    void* objetos[] = { obj1, obj2, obj3 };

    // Loop polimórfico
    for (int i = 0; i < 3; i++) {
        identificar_animal(animais[i]);        // RTTI
        animais[i]->falar(objetos[i]);         // método virtual
    }

    // Destruir tudo
    for (int i = 0; i < 3; i++) {
        animais[i]->destruir(objetos[i]);      // destrutor virtual
    }

    return 0;
}
