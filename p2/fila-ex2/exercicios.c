#include "fila.h"

void separar_impar_par(t_fila *fila, t_fila *pares, t_fila *impares) {
    int valor;
    int tamanho = 0;
    t_fila *temp = constroi_fila();

    while (desenfileira(&valor, fila)) {
        enfileira(valor, temp);
        if (valor % 2 == 0) {
            enfileira(valor, pares);
        } else {
            enfileira(valor, impares);
        }
        tamanho++;
    }

    // Restaurar fila original
    for (int i = 0; i < tamanho; i++) {
        desenfileira(&valor, temp);
        enfileira(valor, fila);
    }
    free(temp);
}

void move_menor_para_maior(t_fila *f1, t_fila *f2) {
    // Contar elementos
    int c1 = 0, c2 = 0, temp;
    t_fila *tmp1 = constroi_fila();
    t_fila *tmp2 = constroi_fila();

    // Contar f1
    while (desenfileira(&temp, f1)) {
        enfileira(temp, tmp1);
        c1++;
    }
    while (desenfileira(&temp, tmp1)) {
        enfileira(temp, f1);
    }

    // Contar f2
    while (desenfileira(&temp, f2)) {
        enfileira(temp, tmp2);
        c2++;
    }
    while (desenfileira(&temp, tmp2)) {
        enfileira(temp, f2);
    }

    // Esvaziar a menor fila
    if (c1 <= c2) {
        while (desenfileira(&temp, f1)) {
            enfileira(temp, f2);
        }
    } else {
        while (desenfileira(&temp, f2)) {
            enfileira(temp, f1);
        }
    }

    free(tmp1);
    free(tmp2);
}