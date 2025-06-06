#include "fila.h"

t_fila *constroi_fila (int capacidade){
    t_fila *fila = (t_fila *) malloc (sizeof(t_fila));
    fila->capacidade = capacidade;
    fila->primeiro = 0;
    fila->ultimo = 0;
    fila->ocupacao = 0;
    fila->dados = (int *) malloc (capacidade * sizeof(int));
   return fila; 
}

int fila_cheia (t_fila *fila){
    return fila->ocupacao == fila->capacidade;
}

int fila_vazia (t_fila *fila){
    return fila->ocupacao == 0;
}
int proxima(int pos, int capacidade){
    return (pos+1) % capacidade;
}

void exibir_fila (t_fila *fila){
    if (fila_vazia(fila)) printf("Fila vazia");
    int i = fila->primeiro;
    do {
        printf("Fila: %d\n", fila->dados[i]);
        i = proxima(i, fila->capacidade);
    } while (i!=fila->ultimo);
    printf("\n");
}

// int enfileira (int i, t_fila *fila){
//     if (fila_cheia(fila)) return 0;
//     fila->dados[fila->ultimo] = i;
//     fila->ultimo = proxima(fila->ultimo, fila->capacidade);
//     fila->ocupacao++;
//     return 1;
// }

int enfileira (int i, t_fila *pf){
    t_no * novo = constroi_no(i);
    if(novo ==NULL){ //alocação de memória falhou
        return 0;
    }
    if(fila_vazia(pf)){
        pf->primeiro = novo;
    }
    else{
        pf->ultimo->prox = novo;    
    }
    pf->ultimo = novo;
    return 1;
}

// int desenfileira (int *i, t_fila *fila){
//     if (fila_vazia(fila)) return 0;
//     *i = fila->dados[fila->primeiro];
//     fila->primeiro = proxima(fila->primeiro, fila->capacidade);
//     fila->ocupacao--;
//     return 1;
// }

int desenfileira (int *i, t_fila *pf){
    if(fila_vazia(pf)){
        return 0;
    }
    *i = pf->primeiro->info;
    t_no * aux = pf->primeiro;
    pf->primeiro = pf->primeiro->prox;
    if(pf->primeiro == NULL){  //esvaziou a fila
        pf->ultimo = NULL;
    }
    free(aux);
    return 1;
}


void mostra_vetor (t_fila *fila){
    if (fila_vazia(fila)){
        for (int i=0; i< fila->capacidade; i++){
            printf("_ ");
        }
    } else if (fila_cheia(fila)){
        for (int i=0; i<fila->capacidade; i++){
            printf ("%d", fila->dados[i]);   
        }
    } else if (fila->primeiro < fila->ultimo){
        for (int i=0; i<fila->primeiro; i++)
            printf("_ ");
        for (int i=fila->primeiro; i<fila->ultimo;i++)
            printf("%d", fila->dados[i]);
        for (int i=fila->ultimo; i<fila->capacidade; i++)
            printf ("_ ");
    } else{
        for (int i=0; i<fila->ultimo; i++)
            printf("%d", fila->dados[i]);
        for (int i=fila->ultimo; i<fila->primeiro;i++)
            printf("_ ");
        for (int i=fila->primeiro; i<fila->capacidade; i++)
            printf ("%d", fila->dados[i]);
    }
    printf("\n");
}

void mostra_fila (t_fila *pf){
    if(fila_vazia(pf)){
        printf("Fila vazia!");
    }
    else{
        t_no * aux = pf->primeiro;
        while(aux != NULL){
            printf("%d ", aux->info);
            aux = aux->prox;
        }
    }
}

// void exibe_primeiro(t_fila *fila){
//     if (fila_vazia(pf)) printf("\n");
//     else printf("%d\n", pf-> primeiro->info);
// }

void exibe_primeiro(t_fila *pf){
    if(fila_vazia(pf)){
        printf("\nFila vazia");
    }
    else{
        printf("\n %d", pf->primeiro->info);
    }
}

// int devolve_primeiro (t_fila *fila){
//     if (fila_vazia(pf)) return -1;
//     return pf->primeiro->info;
// }

// void exibe_ultimo (t_fila *fila){
//     if (fila_vazia(pf)) printf("\n");
//     else printf("%d\n", pf->ultimo->info);
// }

// int devolve_ultimo(t_fila *fila){
//     if (fila_vazia(pf)) return -1;
//     return pf->primeiro->info;
// }


int devolve_primeiro(t_fila *pf){
    if (fila_vazia(pf)) return -1;
    return pf->primeiro->info;
}
void exibe_ultimo(t_fila *pf){
    if (fila_vazia(pf)) printf("\n");
    else printf("%d\n", pf->ultimo->info);
}
int devolve_ultimo(t_fila *pf){
    if (fila_vazia(pf)) return -1;
    return pf->ultimo->info;
}