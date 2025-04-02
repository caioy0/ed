// #include <stdio.h>

// int main (){
//     int par[10], impar[10], numeros [10];
//     int contpar= 0, contimp = 0;
//     do {
//         for (int i=0; i<10; i++){
//             printf("Digite 10 numeros inteiros: ");
//             scanf("%d", &numeros[i]);
//         }
//         for (int i=0; i<10; i++){
//             if (numeros[i] %2 == 0){
//                 par[contpar++] = numeros[i]; // por que do ++
//             } else{
//                 impar[contimp++] = numeros [i];
//             }
//         }
//     } while (numeros[0] != numeros[9]);

//     printf("Numeros: %d\n");
//     for (int i = 0; i <10; i++){
//         printf("%d", par[i]);
//     }
//     printf("Numeros: %d\n");
//     for (int i = 0; i <10; i++){
//         printf("%d", impar[i]);
//     }
//     return 0;
// }
/*
#include <stdio.h> 
#include <stdlib.h> 
void f1(int a){ 
 printf ("%d", a); 
 a += a; 
 printf ("%d", a); 
} 
 
int main(int argc, char **argv) { 
 int a = 2; 
 int b = 3; 
 f1 (a); 
 f1 (b); 
 printf ("%d %d", a, b); 
 return 0; 
}
*/

#include <stdio.h>
#include <math.h>

int main() {
    int chose = 1;
    do {
        printf("Escolha o exercicio!\n");
        printf("Vetores: 1-7\n0-sair\nInput: ");
        scanf("%d", &chose);
        // melhor usar string?
        // getc("");
        //case "1"
        switch (chose)
        {
            case 1:{  // ex 1
                int par[10], impar[10], numeros[10];
                int contpar = 0, contimp = 0;
            
                printf("Digite 10 numeros inteiros:\n");
                for (int i = 0; i < 10; i++) {
                    scanf("%d", &numeros[i]);
                    if (numeros[i] % 2 == 0) {
                        par[contpar++] = numeros[i]; 
                    } else {
                        impar[contimp++] = numeros[i];
                    }
                }
                printf("\nNumeros pares: ");
                for (int i = 0; i < contpar; i++) {
                    printf("%d ", par[i]);
                }
                printf("\nNumeros impares: ");
                for (int i = 0; i < contimp; i++) {
                    printf("%d ", impar[i]);
                }
            
                printf("\n");
            } break;
            
            case 2:{ // Ex2
                int num[10], mul3[10];
                int count = 0;
                printf("Insira 10 numeros: ");
                for (int i=0; i<10; i++){
                    scanf("%d", &num[i]);
                }
                for (int i=0; i<9; i++){
                    if (num[i] %3 == 0){
                        mul3[count++] = num[i];
                    }
                }
                printf("Numeros multiplos de 3: \n");
                for (int i=0;i<count;i++){
                    printf("%d ", mul3[i]);
                }
                printf("\n");
            } break;

            case 3:{
                int v1[5], v2[5], v3[10];
                
                printf("Digite 5 numeros inteiros: ");
                for (int i = 0; i < 5; i++) {
                    scanf("%d", &v1[i]);
                }
                printf("\nDigite 5 numeros novamente: ");
                for (int i = 0; i < 5; i++) {
                    scanf("%d", &v2[i]);
                }
                int j = 0;
                for (int i = 0; i < 5; i++) {
                    v3[j++] = v1[i];
                    v3[j++] = v2[i];
                }
                
                printf("\nV1: ");
                for (int i = 0; i < 5; i++) {
                    printf("%d ", v1[i]);
                }
                printf("\nV2: ");
                for (int i = 0; i < 5; i++) {
                    printf("%d ", v2[i]);
                }

                printf("\nV3: ");
                for (int i = 0; i < 10; i++) {
                    printf("%d ", v3[i]);
                }
                printf("\n");

            }break;

            case 4:{
                int v[10];
                int size = 0; // size opcional?
                printf("Insira 10 numeros: ");
                for (int i=0; i<10; i++){
                    scanf("%d", &v[i]);
                    size++;
                    if (v[i] == 0) break;
                }
                printf("vetor: ");
                // for (int i=0;i<size;i++){
                //     printf("%d ", v[i]);
                // }
                for (int i=0;i<10;i++){
                    printf("%d ", v[i]);
                }
                printf("O vetor possui: %d\n", size);
                printf("\n");
            }break;

            case 5:{
                int v1[10], v2[10], v3[10];
                int size = 0;
                printf("Insira 10 numeros: ");
                for (int i=0; i<10; i++){
                    scanf("%d", &v1[i]);
                }
                printf("Insira 10 numeros novamente: ");
                for (int i=0; i<10; i++){
                    scanf("%d", &v2[i]);
                }
                int j = 0;
                for (int i=0;i<10;i++){
                    v3[j++] = v1[i]*v2[i];
                }
                printf("vetor 3: ");
                for (int i=0;i<10;i++){
                    printf("%d ", v3[i]);
                }
                printf("\n");
            }break;

            case 6:{
                int numeros[10];
                int contpar = 0, contimp = 0;
            
                printf("Digite 10 numeros inteiros:\n");
                for (int i = 0; i < 10; i++) {
                    scanf("%d", &numeros[i]);
                    if (numeros[i] % 2 == 0) {
                        numeros[i] = 0; 
                    } else {
                        numeros[i] = 1;
                    }
                }
                printf("\nVetor: ");
                for (int i = 0; i < 10; i++) {
                    printf("%d ", numeros[i]);
                }
            }break;
            
            case 7:{
                int v[8];
                printf("Digite 8 numeros inteiros:\n");
                for (int i = 0; i < 8; i++) { // correto seria um contador
                    scanf("%d", &v[i]);
                }
                // Bubble sort
                for (int i = 0; i < 8 - 1; i++) {  // Passadas
                    for (int j = 0; j < 8 - i - 1; j++) {  // Comparações
                        if (v[j] > v[j + 1]) {  // Troca se estiver fora de ordem
                            int aux = v[j];
                            v[j] = v[j + 1];
                            v[j + 1] = aux;
                        }
                    }
                }
                printf("\nVetor: ");
                for (int i = 0; i < 8; i++) {
                    printf("%d ", v[i]);
                }

            }break;

            case 8:{
                ponto p1, p2;
                circulo c;
                
                // Entrada dos pontos
                printf("Digite as coordenadas do primeiro ponto (x y): ");
                scanf("%f %f", &p1.x, &p1.y);
                
                printf("Digite as coordenadas do segundo ponto (x y): ");
                scanf("%f %f", &p2.x, &p2.y);
                
                // Calcula e exibe a distância entre os dois pontos
                float distancia = calcular_distancia(p1, p2);
                printf("\nDistancia entre os pontos: %.2f\n", distancia);
                
                // Entrada do círculo
                printf("\nDigite as coordenadas do ponto central do círculo (x y): ");
                scanf("%f %f", &c.ponto_central.x, &c.ponto_central.y);
                
                printf("Digite o raio do círculo: ");
                scanf("%f", &c.raio);
                
                // Verifica se p1 está dentro do círculo
                if (ponto_no_circulo(c, p1)) {
                    printf("\nO primeiro ponto pertence ao círculo.\n");
                } else {
                    printf("\nO primeiro ponto NAO pertence ao círculo.\n");
                }
            }break;
            
            case 0:
                chose = 0;
            break;
        
        default:
            break;
        }
    }while (chose != 0);
    
    return 0;
    printf("\nend\n");
}

typedef struct {
    float x, y;
}ponto;

typedef struct {
    float raio, ponto_central;
}circulo;

void distancia(ponto p1, ponto p2){
    return sqrt((p1.x-p2.x)*(p1.y-p2.y));
}

int ponto_no_circulo(circulo c, ponto p) {
    float distancia = calcular_distancia(c.ponto_central, p);
    return distancia <= c.raio;  // Porque ele aponta pra tras?
}

void bubble_sort (int v[],int n){
    for (int i=1;i<n;i++)
        for(int j=0;j<n-i;j++)
            if (v[j]> v[j+1]){
                int aux = v[1];
                v[i+1] = aux;
            }
}