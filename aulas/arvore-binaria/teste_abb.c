#include "abb.c"
#include <time.h>

int main (){
    t_abb abb;
    inicia_abb (&abb);
    if (abb_vazia (&abb)) printf("arvore inicializada vazia\n");
    else printf("incializda, nao esta vazia\n");

    for (int i=1; i<=12; i++){
        int n = rand () % 20;
        printf("%d", n);
        insere (n, &abb);
    }
    imprime (&abb);
    if (busca (10,&abb)) printf("10 esta na arvore");
    else printf ("10 nao esta na arvore");
    return 0;
}
