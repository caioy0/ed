#include <stdio.h>

int main(){
    int a,b;
    printf("digite a: ");
    scanf("%d", &a);
    printf("digite b: ");
    scanf("%d", &b);
    if(a >= b){
        if (a % b == 0){
            printf("se multiplicou");
        }
        else{
            printf("Nao se multiplicou");
        }
    }
    else{
        if(b % a == 0){
            printf("Sao multiplos");
        }else{
            printf("Nao sao multiplos");
        }
    }
    return 0;
}
