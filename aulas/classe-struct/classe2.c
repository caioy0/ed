#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// "Classe" Pessoa com métodos
typedef struct Pessoa {
    char *nome;
    int idade;

    // Métodos
    void (*mostrar)(struct Pessoa *this);
    void (*aniversario)(struct Pessoa *this);
    void (*destruir)(struct Pessoa *this);  // destrutor
} Pessoa;

// Método: mostrar
void pessoa_mostrar(Pessoa *this) {
    printf("Nome: %s\n", this->nome);
    printf("Idade: %d\n", this->idade);
}

// Método: aniversario
void pessoa_aniversario(Pessoa *this) {
    this->idade++;
    printf("%s fez aniversário! Nova idade: %d\n", this->nome, this->idade);
}

// Destrutor: libera memória alocada
void pessoa_destruir(Pessoa *this) {
    if (this->nome != NULL) {
        free(this->nome);
    }
    free(this);
}

// "Construtor": aloca e inicializa a Pessoa
Pessoa* criar_pessoa(const char *nome, int idade) {
    Pessoa *p = malloc(sizeof(Pessoa));
    if (p == NULL) {
        perror("Erro ao alocar Pessoa");
        exit(1);
    }

    // Aloca e copia o nome
    p->nome = malloc(strlen(nome) + 1);
    if (p->nome == NULL) {
        perror("Erro ao alocar nome");
        free(p);
        exit(1);
    }
    strcpy(p->nome, nome);

    p->idade = idade;

    // Vincula métodos
    p->mostrar = pessoa_mostrar;
    p->aniversario = pessoa_aniversario;
    p->destruir = pessoa_destruir;

    return p;
}

// Programa principal
int main() {
    Pessoa *maria = criar_pessoa("Maria", 25);

    maria->mostrar(maria);
    maria->aniversario(maria);
    maria->mostrar(maria);

    // Libera memória (estilo "destrutor")
    maria->destruir(maria);

    return 0;
}
