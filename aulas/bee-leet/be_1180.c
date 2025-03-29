#include <stdio.h>

int main(){
    int n, x, m;
    scanf("%d", &n);
    //x = (int *) malloc (n * sizeof(int)):
    scanf("%d", &m);
    int pos = 0;
    for (int i = 1; i < n; i++){
        scanf("%d", &x);
        if (x < m){
            m = x;
            pos = i;
        }
    }
    printf("Menor valor: %d\n", m);
    printf("Posicao: %d\n", pos);
    return 0;
}
