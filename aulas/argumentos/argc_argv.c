#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    int i, soma;
    // for (i=0; i<argc; i++){
    //     printf("argumento %d: %s \n", i, argv[i]);
    // }
    for (i=1, soma=0; i<argc; i++){
        soma = soma + atoi(argv[i]);
    }
    i = printf("soma = %d\n",soma);
    printf("fyk: i = %d\n", i);
    return 0;
} 