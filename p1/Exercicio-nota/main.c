#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct{
    char placa[8];
    int manobras;
} Carro;

int main(){
    Carro estacionamento[10];
    int topo = 0; // Contador de carros 
    char operacao; // '0' para entrada, '1' para saída
    char placa[8]; // Placa do carro copiada da struct
    printf("Placa do carro como string\n");
    while (1)  {
        printf("Input para entrada ou saída (ex: 0(entrada) ABC1234(placa) -> 1(saida) ABC1234(placa)):\n");
        if (scanf(" %c %7s", &operacao, placa) != 2) { // INPUT
            printf("Entrada inválida. Encerrando programa.\n");
            break;
        }
        if (operacao == '0') { // ENTRADA -> cadastra a placa do carro
            if (topo >= 10) { // limite == 10 carros
                printf("Carro %s chegou, mas estacionamento cheio. Indo embora.\n", placa);
            } else {
                strcpy(estacionamento[topo].placa, placa); // placa copiada da struct
                estacionamento[topo].manobras = 0; // Manobras zeradas
                topo++; // Adiciona o carro
                printf("Carro %s entrou no estacionamento.\n", placa);
            }
        } else if (operacao == '1') { // SAIDA
            int i, j;
            int encontrado = 0; 
            for (i = 0; i < topo; i++) { // Pesquisa a placa do carro e verifica 
                if (strcmp(estacionamento[i].placa, placa) == 0) {
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) { // Placa do carro nao esta no array
                printf("Carro %s não está no estacionamento.\n", placa);
            } else { // Carro encontrado, codigo complexo a seguir
                for (j = i + 1; j < topo; j++) {
                    estacionamento[j].manobras++; // carro no array manobrado
                }
                printf("Carro %s saiu do estacionamento. Foi manobrado %d vezes.\n", estacionamento[i].placa, estacionamento[i].manobras); 
                // Reorganiza o estacionamento (remove o carro)
                for (j = i; j < topo - 1; j++) {
                    estacionamento[j] = estacionamento[j + 1]; // move o carro para a esquerda
                }
                topo--; // remove o carro do topo
            }
        } else { // ERROR durante input
            printf("Operação inválida. Use '0' para entrada ou '1' para saída.\n");
        }
    }
    return 0;
}