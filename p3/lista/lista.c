#include "lista.h"
#include <stdio.h>

void constroi_lista(t_lista *lista){
    lista->primeiro = lista->ultimo = NULL;
}
int lista_vazia(t_lista *lista){
    return !lista->primeiro;
}
void insere_inicio(int i, t_lista *lista){
    t_no * novo = constroi_no(i);
    if(lista_vazia(lista)) lista->ultimo = novo;
    else novo->proximo = lista->primeiro;
    lista->primeiro = novo;
}
int remove_inicio(t_lista *lista){
    if (lista_vazia(lista)) return -1;
    int temp = lista->primeiro->info;
    t_no * aux = lista->primeiro; // struct no auxiliar que aponta para o primeiro
    lista->primeiro = lista->primeiro->proximo;
    if (lista->primeiro == NULL) lista->ultimo == NULL; // esvaziou a lista
    free(aux);
    return temp;
}
void insere_fim(int i, t_lista *lista){
    t_no * novo = constroi_no(i);
    if (lista_vazia(lista)) lista->primeiro = novo;
    else lista->ultimo->proximo = novo;
    lista->ultimo = novo;
}
int remove_fim(t_lista *lista){
    // cenario 1: lista vazia
    if (lista_vazia(lista)) return -1;
    // cenario 2: lista tem um elemento so
    int temp;
    if (lista->primeiro == lista->ultimo){
        temp = lista->primeiro->info;
        free(lista->primeiro);
        lista->primeiro = lista->ultimo = NULL;
    }
    else{
        t_no * runner = lista->primeiro;
        while(runner->proximo != lista->ultimo) runner = runner->proximo;
        temp = lista->ultimo->info; // aponta pra ultimo no
        free(lista->ultimo); // remove
        runner->proximo = NULL;
        lista->ultimo = runner;
    }
    return temp;
}


void mostra_lista (t_lista *lista){
    if (lista_vazia(lista)) printf("Lista vazia!\n");
    else{
        t_no * runner = lista->primeiro;
        while (runner != NULL){
            printf("[%d] -> ", runner->info);
            runner = runner->proximo;
        }
        printf("\\\\\n");
    }
}

int pares(t_lista *lista){
    if (lista_vazia(lista)) return 0;
    else{
        t_no * runner = lista->primeiro;
        t_lista novalista;
        constroi_lista(&novalista);
        while (runner != NULL) {
            if (runner->info % 2 == 0) {
                insere_inicio(runner->info, &novalista);
            }
            runner = runner->proximo;
        }
        mostra_lista(&novalista);
        return 1;
    }
}

int conta_pares (t_lista *lista, int *i){
    if (lista_vazia(lista)) return 0;
    else{
        t_no *runner = lista->primeiro;
        int contador = 0;
        while (runner != NULL){
            if (runner->info %2 == 0) contador ++;
            runner = runner->proximo;
        }
        *i = contador;
        return 1;
    }
}

void inverter (t_lista *l1, t_lista *lista){
    if(lista_vazia(l1) || lista_vazia(lista)) printf ("lista vazia!\n");
    t_no *runner = l1->primeiro;
    while (runner != NULL) {
        insere_inicio(runner->info, lista); 
        runner = runner->proximo; 
    }
}