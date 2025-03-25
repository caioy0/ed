#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 37;
    printf("valor de a (decimal)= %d\n",a);
    printf("valor de a (hexadecimal) = %x\n", a);
    printf("endereco de a = %p\n", &a);
    printf("caracter equivalente de a: %c\n", a);
    //printf("string de a: %s\n", &a); erro de acesso a memoria
    printf("string da referencia de a: %s\n", &a);
    printf("");
    return 0;
}