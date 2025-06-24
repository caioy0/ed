#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

void inicia_abb (t_abb *abb){
    abb->raiz = NULL;
}

int abb_vazia (t_abb *abb){
    return abb->raiz == NULL;
}

void insere (int i, t_abb *abb){
    t_no * novo = constroi_no(i);
    if (abb_vazia(abb)) abb->raiz = novo;
    else insere_rec(novo, abb->raiz);
}

void insere_rec (t_no *novo, t_no *atual){ // ir para direita
    if (novo->info > atual->info){
        if (atual->dir == NULL) atual -> dir = novo;
        else insere_rec(novo, atual->dir);
    } else { // esquerda
        if (atual->esq == NULL) atual -> esq = novo;
        else insere_rec(novo, atual->esq);
    }
}

void imprime (t_abb *abb){
    if (abb_vazia (abb)) printf("arvore vazia\n");
    else imprime_rec (abb->raiz);
}

void imprime_rec (t_no *atual){
    if (atual != NULL) {
        imprime_rec(atual->esq); // Faz até que atual == NULL, quando isso acontece ele desempilha e começa a exibir as info de cada nó da arvore 
        printf("%d ", atual->info);
        imprime_rec(atual->dir);
    }
}
int busca (int x, t_abb *abb){
    if (abb_vazia(abb)) return 0;
    return busca_rec (x,abb->raiz);
}

int busca_rec (int x, t_no *atual){
    if (atual == NULL) return 0;
    if (atual->info ==x) return 1; //achou!
    if (x > atual->info) return busca_rec(x, atual->dir);
    return busca_rec (x,atual->esq);
}

int conta_x (int x, t_abb *abb){
    if (abb_vazia(abb)) return 0;
    return conta_x_rec(x, abb->raiz);
}
int conta_x_rec (int x, t_no *atual){
    if (atual == NULL) return 0;
    int cont = conta_x_rec (x, atual->esq) + conta_x_rec (x, atual->dir);
    return atual->info == x ? cont+1 : cont;
    // if (atual->info == x) {
    //     return cont + 1;
    // } else {
    //     return cont;
    // }
}