#include "pilha.h"
#include <stdio.h>

void constroi_pilha (t_pilha *pilha) {
    pilha->topo = NULL;
}
int pilha_vazia (t_pilha *pilha) {
    return !pilha->topo;
}
void push (int i, t_pilha *pilha) { // construtor de no + adicionar dados
    t_no * novo = constroi_no(i);
    if (!pilha_vazia(pilha)) novo->prox = pilha->topo;
    pilha->topo = novo;
}
int pop (t_pilha *pilha, int * temp) {
    if (pilha_vazia(pilha)) return 0;
    *temp = pilha->topo->info;
    t_no * aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(aux);
    return 1;
}
void exibe_pilha (t_pilha * pilha) {
    if (pilha_vazia(pilha)) printf ("pilha vazia\n"); // pilha vazia aviso
    else {
        t_no * runner = pilha->topo;
        while (runner != NULL) {
            printf ("[%d] -> ", runner->info);
            runner = runner->prox;
        }
        printf ("\\\\\n");
    }
}
void inverter(t_pilha *pilha) { 
    t_pilha aux1, aux2;
    constroi_pilha(&aux1);
    constroi_pilha(&aux2);
    int temp;

    while (pop(pilha, &temp)) { // Desempilha da pilha original
        push(temp, &aux1); // Empilha na primeira auxiliar
    }

    while (pop(&aux1, &temp)) { // Desempilha da primeira auxiliar
        push(temp, &aux2); // Empilha na segunda auxiliar
    }

    while (pop(&aux2, &temp)) { // Desempilha da segunda auxiliar
        push(temp, pilha); // Empilha de volta na pilha original
    }
}

void intercalar(t_pilha *p1, t_pilha *p2) {
    if (pilha_vazia(p1) && pilha_vazia(p2)) {
        printf("Ambas as pilhas estão vazias.\n");
        return;
    }

    t_pilha aux1, aux2, resultado;
    constroi_pilha(&aux1);
    constroi_pilha(&aux2);
    constroi_pilha(&resultado);
    int temp;

    while (pop(p1, &temp)) {
        push(temp, &aux1);
    }

    while (pop(p2, &temp)) {
        push(temp, &aux2);
    }

    while (!pilha_vazia(&aux1) || !pilha_vazia(&aux2)) {
        if (!pilha_vazia(&aux1)) {
            pop(&aux1, &temp);
            push(temp, &resultado);
        }
        if (!pilha_vazia(&aux2)) {
            pop(&aux2, &temp);
            push(temp, &resultado);
        }
    }
    while (pop(&resultado, &temp)) {
        push(temp, p1);
    }
}


// int busca_elemento(int *aux, t_pilha *pilha) {
    //     if (pilha_vazia(pilha)) return 0;
    
    //     t_no *runner = pilha->topo;
    //     while (runner != NULL) {
//         if (runner->info == aux) {
//             printf("%d encontrado.\n", aux);
//             return 1;
//         }
//         runner = runner->prox;
//     }
//     printf("%d nao encontrado.\n", aux);
//     return 0;
// }

// int conta_ocorrencias(t_pilha *pilha, int aux) {
//     int contador = 0;
//     if (pilha_vazia(pilha)) return 0;
//     t_no *runner = pilha->topo;
//     while (runner != NULL) {
//         if (runner->info == aux) {
//             contador++;
//         }
//         runner = runner->prox;
//     }

//     return contador;
// }

// void ordenar_crescente(t_pilha *pilha) {
//     if (pilha_vazia(pilha)) {
//         printf("Pilha vazia.\n");
//         return;
//     }

//     t_pilha aux;
//     constroi_pilha(&aux);
//     int temp;

//     while (pop(pilha, &temp)) {
//         int topo_aux;

//         // Enquanto o topo da auxiliar for maior que temp, devolve pra original
//         while (!pilha_vazia(&aux) && aux.topo->info > temp) {
//             pop(&aux, &topo_aux);
//             push(pilha, topo_aux);
//         }

//         push(&aux, temp);
//     }

//     // Transfere de volta para a pilha original (ainda em ordem crescente)
//     while (pop(&aux, &temp)) {
//         push(pilha, temp);
//     }
// }