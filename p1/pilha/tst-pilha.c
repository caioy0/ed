#include "pilha.c"

int main (){
    t_pilha pilha; // Inicia "variavel pilha"
    constroi_pilha(10, &pilha); // Ta chumbado o tamanho da pilha hahaha
                        // t_pilha *p e &pilha apontam na memoria.
    exibe_pilha(&pilha); // &?
    push(10, &pilha); 
    exibe_pilha(&pilha);
    int ch = 1;
    do{
        printf("Escolha:\n1-Inserir dado na pilha\n2-Remover(pop)\n");
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
            if (elementos > 1){
                for (int i=0; i < elementos; i++){
                    pop(&pilha,&aux);
                }
                printf("%d foi desempilhado\n", aux);
            }else{
                if (pop(&pilha, &aux)){
                    printf("%d foi desempilhado\n", aux);
                }else{
                    printf("pilha vazia, nao foi possivle desempilhar\n");
                }
            }
        }break;
        case 3:{
            exibe_pilha(&pilha);
        }break;
        case 4:{
            inverter_pilha(&pilha);
        }break;
        case 5:{
            int par[10], impar[10];
            int p = (int *) malloc (sizeof(int));
            int contpar = 0, contimp = 0;
            
            printf("Digite 10 numeros inteiros:\n");
            for (int i=p->topo-1; i < 10; i++) {
                 // !
                if (p->dados[i] % 2 == 0) {
                    par[contpar++] = par[i]; 
                } else {
                    impar[contimp++] = impar[i];
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