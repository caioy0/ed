#include <stdio.h>

int main(){
    
    //ler uma sequencia de numeros, ate encontrar EOF, soma-los e exibir a soma
    int a, b, n;
    
    /*
    printf("Digite dois numeros: ");
    n = scanf("%d%d",&a,&b);
    printf("\nn = %d\n",n);
    */

    while ((scanf("%d", &a)) != EOF){
        printf("%d \n", a);
    }
    printf("\nacabou o arquivo");
    return 0;
}
