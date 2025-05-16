#include <stdio.h>
#include "pilha.h"
#include "pilha.c"

// ex 1

void remove_n_elementos(t_pilha *p, int n) {
    int temp;
    if (n <= 0 || n > p->topo) return;
    for (int i = 0; i < n; i++) {
        pop(p, &temp);
    }
}

// ex 2

void inverter_pilha(t_pilha *pilha) {
    t_pilha aux1, aux2;
    int temp;

    constroi_pilha(&aux1);
    constroi_pilha(&aux2);

    while (pop(pilha, &temp)) {
        push(temp, &aux1);
    }

    while (pop(&aux1, &temp)) {
        push(temp, &aux2);
    }

    while (pop(&aux2, &temp)) {
        push(temp, pilha);
    }
}

// ex 3

void separa_pares_impares(t_pilha *p1, t_pilha *pares, t_pilha *impares) {
    int valor;
    t_pilha temp;
    // constroi_pilha(p1->capacidade, &temp);

    while (!pilha_vazia(p1)) {
        pop(p1, &valor);
        push(valor, &temp);
    }

    while (!pilha_vazia(&temp)) {
        pop(&temp, &valor);
        if (valor % 2 == 0)
            push(valor, pares);
        else
            push(valor, impares);
        push(valor, p1);  // restaurar p1
    }
}
// ex 8

void transfere_mantendo_ordem(t_pilha *p1, t_pilha *p2) {
    t_pilha aux;
    int temp;

    constroi_pilha(&aux);

    while (pop(p1, &temp)) {
        push(temp, &aux);
    }

    while (pop(&aux, &temp)) {
        push(temp, p1);  // Restaura p1
        push(temp, p2);  // Transfere mantendo ordem
    }
}


// ex 7

void teste_exercicio7() {
    t_pilha p1, p2, p3;
    int temp;

    inicializa_pilha(&p1);
    inicializa_pilha(&p2);
    inicializa_pilha(&p3);

    // Supondo que p1 comece com: [4, 3, 2, 1] (topo = 4)
    empilha(1, &p1);
    empilha(2, &p1);
    empilha(3, &p1);
    empilha(4, &p1);

    temp = desempilha(&p1);
    empilha(temp, &p2);

    empilha(desempilha(&p1), &p3);

    empilha(desempilha(&p1), &p2);

    temp = desempilha(&p1);
    empilha(temp, &p3);

    empilha(desempilha(&p2), &p1);

    empilha(desempilha(&p2), &p3);

    empilha(desempilha(&p1), &p3);
}