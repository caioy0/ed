#include "pilha.c"

int main (){
    t_pilha pilha; // Inicia "variavel pilha"
    constroi_pilha(10, &pilha); // E tem que construir a pilha?
                        // Capacidade e t_pilha * wtffffff
    exibe_pilha(&pilha); // &?
    push(10, &pilha); 
    exibe_pilha(&pilha);
    int ch = 1;
    do{
        printf("Escolha:1-Inserir dado na pilha\n2-Remover(pop)\n");
        printf("3-Mostrar pilha\n4-Inverter Pilha\n0-Sair\nInput: ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:{
            int num;
            printf("Digite numero int para a pilha: ");
            scanf("%d", &num);
            push(num, &pilha);
        } break;
        case 2:{
            int aux, elementos;
            printf("Quantos elementos quer remover?: ");
            scanf("%d", &elementos);
            if (pop(&pilha, &aux)){
                printf("%d foi desempilhado\n", aux);
            }else{
                printf("pilha vazia, nao foi possivle desempilhar\n");
            }
        }break;
        case 3:{
            exibe_pilha(&pilha);
        }break;
        case 4:{
            //inverter_pilha(&pilha);
        }break;

        case 0:{
            ch = 0;
        }break;
        
        default:
            printf("Wtf?\n");
            break;
        }
    } while (ch != 0);
    

    /*
    int aux;
    pop (&pilha, &aux);
    printf("%d foi desempilhado", aux);
    if (pop(&pilha, &aux)){

    }else{
        printf("pilha vazia, nao foi possivel desempilhar");
    }
    exibe_pilha(&pilha);

    int i= 1;
    while (push(i++, &pilha)){
        exibe_pilha(&pilha);
    }

    while (pop(&pilha, &aux)){
        printf("%d, foi desempilhado\n", aux);
    }

    push (10, &pilha);
    inverter_pilha(&pilha);
    exibe_pilha(&pilha);
    */
    return 0;
}