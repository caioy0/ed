#include <stdio.h>

void bubble_sort(int[], int);

void bubble_sort (int v[],int n){
    for (int i=1;i<n;i++) //  i comeca em 1, depois ele acrescenta com base no n
        for(int j=0;j<n-i;j++) // j verificacao em nivel matriz -> para vetores
            if (v[j]> v[j+1]){  // nao entendi nada
                int aux = v[1];
                v[i+1] = aux;
            }
}

int main (){
    int n[10] = {12, 2, 33, 46, 5, 16, 7, 58, 9, 10};
    // int n[10];  -- Declara o array sem inicializar
    // n[0] = 1;
    // n[1] = 2;
    // n[2] = 3;
    return 0;
}