#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// "Classe" Pessoa
typedef struct {
    char nome[50];
    int idade;
    
    // "Métodos"
    void (*mostrar)(struct Pessoa *this);
    void (*aniversario)(struct Pessoa *this);
} Pessoa;

// Método: mostrar
void pessoa_mostrar(Pessoa *this) {
    printf("Nome: %s\n", this->nome);
    printf("Idade: %d\n", this->idade);
}

// Método: aniversario (incrementa idade)
void pessoa_aniversario(Pessoa *this) {
    this->idade++;
    printf("%s fez aniversário! Nova idade: %d\n", this->nome, this->idade);
}

// "Construtor"
Pessoa criar_pessoa(const char *nome, int idade) {
    Pessoa p;
    strncpy(p.nome, nome, sizeof(p.nome));
    p.nome[sizeof(p.nome) - 1] = '\0'; // segurança
    p.idade = idade;

    // Vinculando métodos
    p.mostrar = pessoa_mostrar;
    p.aniversario = pessoa_aniversario;

    return p;
}

// Programa principal
int main() {
    Pessoa joao = criar_pessoa("João", 30);

    joao.mostrar(&joao);       // chama método "mostrar"
    joao.aniversario(&joao);   // chama método "aniversario"
    joao.mostrar(&joao);       // mostra de novo pra ver a mudança

    return 0;
}
// Como tenho dificuldade para entender structs o gpt fez esse codigo para mim,