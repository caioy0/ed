#include <stdio.h>
#include "abb.c"
#include "fila.c"
#include "pilha.c"

int main(){

    int escolha = 1;
    do{
        short opcao = 0;
        printf("Qual exercicio quer mostrar?\n");
        printf("1 | 2 | 3 | 0-sair? \nInput: ");
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 0:
            escolha = 0;
            break;
        default:
            printf("Erro!\n");
            break;
        }
    } while (escolha != 0);
    return 0;
}