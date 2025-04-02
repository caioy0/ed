#include "pilha.h"

int main (){
    int chose = 1;
    do {
        printf("Escolha o exercicio!\n");
        printf("Pilhas: 1-7 \n0-sair \nInput: ");
        scanf("%d", &chose);
        // melhor usar string?
        // getc("");
        //case "1"
        switch (chose)
        {
            case 1:{
                return 0;
            }break;
            
            case 2:{

            }break;
            
            case 0:{

            }break;
        }
    } while (chose != 0);

    return 0;
}