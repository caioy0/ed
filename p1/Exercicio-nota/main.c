#include "pilha.h"
#include <string.h>

int main(){
    t_pilha estacionamento;
    t_pilha aux;
    Carro carro, carro_removido; // carro_removido == carro saindo | carro == carro entrando
    char operacao;
    char placa_input[8];

    constroi_pilha(10, &estacionamento);
    constroi_pilha(10, &aux);

    printf("Placa do carro como string\n");
    while (1) {
        printf("Input (ex: 0 ABC1234 para entrada, 1 ABC1234 para saída):\n");
        if (scanf(" %c %7s", &operacao, placa_input) != 2) {
            printf("Entrada inválida. Encerrando programa.\n");
            break;
        }

        if (operacao == '0') { // ENTRADA
            if (pilha_cheia(&estacionamento)) {
                printf("Carro %s chegou, mas estacionamento cheio. Indo embora.\n", placa_input);
            } else {
                strcpy(carro.placa, placa_input); // copia a placa
                carro.manobras = 0;
                push(*(int*)&carro, (t_pilha*)&estacionamento);
                printf("Carro %s entrou no estacionamento.\n", placa_input);
            }
        } else if (operacao == '1') { // SAÍDA
            int encontrado = 0;
            while (!pilha_vazia(&estacionamento)) { 
                pop(&estacionamento, (int*)&carro_removido); 
                if (strcmp(carro_removido.placa, placa_input) == 0) { // encontrou o carro
                    encontrado = 1;
                    break;
                } else {
                    carro_removido.manobras++; // incrementa manobras
                    push(*(int*)&carro_removido, (t_pilha*)&aux);
                }
            }

            if (!encontrado) {
                printf("Carro %s não está no estacionamento.\n", placa_input);
                // devolve tudo como estava
            } else {
                printf("Carro %s saiu do estacionamento. Foi manobrado %d vezes.\n", carro_removido.placa, carro_removido.manobras);
            }

            // devolve os carros do auxiliar para o estacionamento
            while (!pilha_vazia(&aux)) {
                pop(&aux, (int*)&carro_removido); // remove do auxiliar 
                push(*(int*)&carro_removido, (t_pilha*)&estacionamento); // devolve para o estacionamento
            }
        } else {
            printf("Operação inválida. Use '0' para entrada ou '1' para saída.\n");
        }
    }
    return 0;
}