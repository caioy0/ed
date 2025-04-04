#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ====== "Classe base": Animal ======
typedef struct Animal {
    void (*falar)(void *this);  // método virtual genérico
} Animal;

// ====== "Classe derivada": Pessoa ======
typedef struct Pessoa {
    Animal base;       // composição: Pessoa "é um" Animal
    char *nome;
    int idade;
} Pessoa;

// ====== Implementação do método "falar" para Pessoa ======
void pessoa_falar(void *this) {
    Pessoa *p = (Pessoa *)this;  // cast do ponteiro genérico
    printf("%s diz: Oi, eu sou uma pessoa de %d anos!\n", p->nome, p->idade);
}

// ====== Construtor de Pessoa ======
Pessoa *criar_pessoa(const char *nome, int idade) {
    Pessoa *p = malloc(sizeof(Pessoa));
    if (!p) {
        perror("Erro ao alocar Pessoa");
        exit(1);
    }

    p->nome = malloc(strlen(nome) + 1);
    if (!p->nome) {
        perror("Erro ao alocar nome");
        free(p);
        exit(1);
    }

    strcpy(p->nome, nome);
    p->idade = idade;

    // vincula o método "falar" na parte Animal
    p->base.falar = pessoa_falar;

    return p;
}

// ====== Destrutor de Pessoa ======
void destruir_pessoa(Pessoa *p) {
    free(p->nome);
    free(p);
}

// ====== Função genérica que usa "interface" Animal ======
void fazer_animal_falar(Animal *a, void *obj) {
    a->falar(obj);
}

// ====== Programa principal ======
int main() {
    Pessoa *joao = criar_pessoa("João", 30);

    // Joao é um Pessoa, mas pode ser tratado como Animal
    fazer_animal_falar(&joao->base, joao);

    destruir_pessoa(joao);
    return 0;
}
