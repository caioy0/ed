#include "abb.h"
#include <stdio.h>

void inicia_abb (t_abb * abb){
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

void imprime_rec (t_no * atual){
    if (atual != NULL) {
        imprime_rec(atual->esq);
        printf("%d", atual->info);
        imprime_rec(atual->dir);
    }
}
int busca(int x, t_abb * abb){
    //devolver 1 (verdadeiro), se x estiver na árvore, ou 0, caso contrário
    if (abb_vazia(abb)){
        return 0;
    }
    else{
        busca_rec(x, abb->raiz);
    }
}

int busca_rec(int x, t_no * atual){
    if (atual == NULL) return 0;
    if(atual->info == x) return 1;
    if(x > atual->info) return busca_rec(x, atual->dir);
    else return busca_rec(x, atual->esq);
}