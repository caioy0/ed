#include <stdio.h>
#include <stdlib.h>

void f1 (const int a){
    printf("waaa");
}

int main(int argc, char const *argv[]){
    int x = 10;
    f1(x);
    printf("digite dois inteiros: ");
    int i,j,k;
    j = scanf("%d",&i, &k);
    printf("i = %d\n j = %d\n k= %d\n", i,j,k);
    return 0;
}
