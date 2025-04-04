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

typedef struct {
    float x, y;
}ponto;

typedef struct {
    ponto c;
    float raio;
}circulo;

typedef struct {
    int numerador;
    int denominador;
} fracao;

float distancia(ponto p1, ponto p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

void bubble_sort (int v[],int n){
    for (int i=1;i<n;i++)
        for(int j=0;j<n-i;j++)
            if (v[j]> v[j+1]){
                int aux = v[1];
                v[i+1] = aux;
            }
}

int main() {
    int chose = 1;
    do {
        printf("Escolha o exercicio!\n");
        printf("Vetores: 1-7 \nStruct:8-9\n0-sair\nInput: ");
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
                printf("\n");
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
                printf("\n");
            }break;

            case 8:{ // questao struct
                ponto p1, p2;
                circulo c;
                
                // B:
                printf("Digite as coordenadas do primeiro ponto (x y): ");
                scanf("%f %f", &p1.x, &p1.y);
                printf("Digite as coordenadas do segundo ponto (x y): ");
                scanf("%f %f", &p2.x, &p2.y);
                float distancia2 = distancia(p1, p2);
                printf("\nDistancia entre os pontos: %.2f\n", distancia2);
                
                // C:
                printf("Digite o raio do círculo: ");
                scanf("%f", &c.raio);
                printf("Digite o ponto central: ");
                scanf("%f", &c.ponto_central);
                printf("\nPontos do circulo \nRaio: %.2f \nPonto central : %.2f\n", c.raio, c.ponto_central);
                float area = 3.14*(c.raio*c.raio);
                if (p1.x || p1.y == area) {
                    printf("\nO primeiro ponto pertence ao círculo.\n");
                }else {
                    printf("\nO primeiro ponto NAO pertence ao círculo.\n");
                }
                // Ponto 2
                if (p2.x == area|| p2.y == area){
                    printf("\nO segundo ponto pertence ao círculo.\n");
                }else {
                    printf("\nO primeiro ponto NAO pertence ao círculo.\n");
                }
                printf("\n");
            }break;

            case 9: {
                fracao f,f2;
                printf("Numerador: ");
                scanf("%d", &f.numerador);
                printf("Denominador: ");
                scanf("%d", &f.denominador);
                printf("Fracao: %d/%d\n", f.numerador, f.denominador);
                printf("---------------------------\n");
                printf("Numerador: ");
                scanf("%d", &f2.numerador);
                printf("Denominador: ");
                scanf("%d", &f2.denominador);
                printf("Fracao: %d/%d\n", f2.numerador, f2.denominador);
                printf("---------------------------\n");
                float f1r, f2r;
                f1r = (float) f.numerador/f.denominador; // Duvidas, es igual (int *)?
                f2r = (float) f2.numerador/f2.denominador;
                if (f2r > f1r) printf("A fracao 2 es maior que a 1\n");
                if (f1r > f2r) printf("A fracao 1 es maior que a 2\n");
                if (f1r == f2r) printf("A fracao 1 es igual que a 2\n");

                float fm = f1r*f2r;
                printf("A multiplicacao da fracao: %.2f\n",fm);
                printf("\n");
            } break;
            
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
