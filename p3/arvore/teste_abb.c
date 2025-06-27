#include "abb.h"

int main (){
    t_abb abb;
    inicia_abb(&abb);
    
    if (abb_vazia (&abb)) printf("arvore inicializada e vazia\n");
    else printf("incializda, nao esta vazia\n");

    for (int i=1; i<=12; i++){
        int n = rand () % 20;
        printf("Inserindo: %d \n", n);
        insere (n, &abb);
    }
    imprime (&abb);
    
    if(busca(10, &abb)) printf("\n10 esta na arvore");
    else printf("\n10 nao esta na arvore");
    printf("\n");

    int contador;
    int num = 3;
    contador = conta_x(num, &abb);  // x precisa ser um valor válido
    printf("O valor %d aparece %d vez na arvore\n", num, contador);

    // remover_par(&abb);
    // imprime(&abb);
    // int temp;
    // max_valor(&abb, &temp);
    // printf("\nO maior valor da arvore: %d", temp);
    return 0;
}