#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int[], int);
void exibe_vetor(int[], int, char *);
void preenche_vetor(int[], int);

int main (){
    int n;
    int *v;
    printf("insira valor: ");
    scanf("%d", &n);
    while(n>0){
        v = (int *) malloc (n* sizeof(int));
        preenche_vetor(v,n);
        exibe_vetor(v,n,"vetor original");
        long int ini = time(0);
        bubble_sort(v,n);
        exibe_vetor(v,n,"vetor ordenado");
        printf("\ntempo de ordenacao: %ld\n", ini);
        free(v);
        printf("\nEscolha o novo tamanho, 0 encerra");
        scanf("%d",&n);
    }

/*
    while(1){
        v = (int *) malloc(4000000);
        printf("o endereco es: %p",v);
        free(v);
    }
*/

    return 0;
}

void preenche_vetor(int v[],int n){
    for (int i=0; i<n; i++)
    v[i] = rand();
}

void exibe_vetor(int v[], int n, char *c){
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void bubble_sort (int v[],int n){
    for (int i=1;i<n;i++)
        for(int j=0;j<n-i;j++)
            if (v[j]> v[j+1]){
                int aux = v[1];
                v[i+1] = aux;
            }
}
