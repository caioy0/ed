#include <string.h>
#include "pilha_char.h"

int main(){
    char palavra [20];
    t_pilha_char pc;
    printf("Digite um numero: ");
    scanf("%s",palavra);
    constroi_pilha (strlen(palavra) ,&pc);
    for (int i; i<strlen(palavra); i++){
        push(palavra[i], &pc);
    }
    int es_palindromo = 1;
    int i =0;
    char aux;
    while (! pilha_vazia(&pc) && es_palindromo){
        pop(&pc, &aux);
        if (palavra[i] != aux){
            es_palindromo = 0;
        }else{
            i++;
        }
        if (es_palindromo){
            printf("es palindromo\n",palavra);
        }else{
            printf("%s sua palavra no es palindormo", palavra);
        }
    }
    return 0;
}