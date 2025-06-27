#include "lista.h"

int main (){
    t_lista lista;
    constroi_lista(&lista);
    mostra_lista(&lista);

    // for (int i=1; i<=10; i++) insere_inicio(i, &lista);
    insere_fim(10,&lista);
    mostra_lista(&lista);
    
    //a funcao que retorne quantos numeros pares existem na lista
    int cont;
    conta_pares(&lista,&cont);
    printf("N de pares: %d\n",cont);
    pares(&lista);
    t_lista l1;
    constroi_lista(&l1);
    for (int i=1; i<=10; i++) insere_inicio(i, &l1);
    mostra_lista(&l1);
    
    inverter(&l1,&lista);
    mostra_lista(&lista);
    
    return 0;
}