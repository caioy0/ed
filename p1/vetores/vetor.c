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

            }break;

            case 4:{

            }break;

            case 5:{

            }break;

            case 6:{

            }break;
            
            case 7:{

            }break;

            case 8:{

            }break;
            
            case 9:{

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
    float x;
    float y;
}ponto;

typedef struct {
    float raio;
    float ponto_central;
}circulo;

// void distancia(float d, float x1, float x2, float y1, float y2){
//     d = sqrt((x1-x2)*2+(y1-y2)*2);
// }