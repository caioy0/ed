#include "fila.h"

// int constroi_fila (int i, t_fila *fila){
//     fila = (t_fila *) malloc (sizeof(t_fila));
//     fila->capacidade = capacidade;
//     fila->primeiro = 0;
//     fila->ultimo = 0;
//     fila->primeiro = 0;
//     fila->ocupacao = 0;
//     fila->dados = (int *) malloc (capacidade * sizeof(int));
// }

t_fila *constroi_fila (int capacidade){
    t_fila *fila = (t_fila *) malloc (sizeof(t_fila));
    fila->capacidade = capacidade;
    fila->primeiro = 0;
    fila->ultimo = 0;
    fila->ocupacao = 0;
    fila->dados = (int *) malloc (capacidade * sizeof(int));
   return fila; 
}

int fila_vazia (t_fila *fila){
    return fila->ocupacao == 0; // !fila->ocupacao
}

int fila_cheia (t_fila *fila){
    return fila->ocupacao == fila->capacidade; 
}

int enfileira (int i, t_fila *fila){
    if (fila_cheia(fila)) return 0;
    fila->dados[fila->ultimo] = i;
    fila->ultimo = proxima(fila->ultimo, fila->capacidade);
    fila->ocupacao++;
    return 1;
}
int desenfileira (t_fila *fila, int *i){
    if (fila_vazia(fila)) return 0;
    *i = fila->dados[fila->primeiro]; // ponteiro para indexar em outra variavel ex: temp.
    fila->primeiro = proxima(fila->primeiro, fila->capacidade); // avanca posicao nova para o proximo numero da lista
    fila->ocupacao--; // Diminui na logica a ocupacao paralela ao vetor estatico [4]
    return 1;
}
int proxima(int pos, int capacidade){
    return (pos+1) % capacidade;
}
void mostrar_fila (t_fila *fila){
    if (fila_vazia(fila)) printf("Fila vazia!\n");
    else{
        int i = fila->primeiro;
        do {
            printf("Fila: %d\n", fila->dados[i]);
            i = proxima(i, fila->capacidade);
        } while (i!=fila->ultimo);
        printf("\n");
    }
}

int fura_fila(int i, t_fila *fila) {
    if (fila_cheia(fila)) return 0;
    //fila->primeiro = proxima(fila->primeiro-1, fila->capacidade);
    fila->primeiro = (fila->primeiro - 1 + fila->capacidade) % fila->capacidade;
    // A fila inteira foi pra frente
    // depois disso a insercao pode ser realizada sem alterar os dados
    fila->dados[fila->primeiro] = i; // Insere o novo numero
    fila->ocupacao++; 
    return 1;
}

int lanterinha (t_fila *fila, int *i){
    if (fila_vazia(fila)) return 0;
    if (fila->ultimo == 0) *i = fila->dados[fila->capacidade-1];
    // Se o próximo índice de inserção for 0, 
    // o último elemento inserido está no final do vetor
    // Pega o último elemento válido (posição circular anterior ao índice 0)
    else *i = fila->dados[fila->ultimo-1]; 
    // Caso normal: o último inserido está em ultimo - 1

    // Ou seja, existem dois casos para acessar corretamente 
    //o último elemento inserido:
    
    // Caso 1: se o índice 'ultimo' for 0, 
    // significa que o último elemento foi inserido 
    // na posição final do vetor (capacidade - 1)

    // Caso 2: para os demais casos (ultimo > 0), 
    // o último valor está na posição 'ultimo - 1'
    return 1;
}

int exibir_primeiro(t_fila *fila, int *i){
    if (fila_vazia(fila)) return 0;
    *i = fila->dados[fila->primeiro];
    return 1;
}

int separar_fila(t_fila *fila){
    if(fila_vazia(fila)) return 0;
    t_fila *par, *impar;
    par = constroi_fila(4);
    impar = constroi_fila(4);

    int tamanho = fila->ocupacao;
    for (int i = 0; i < tamanho; i++) {
        int valor;
        desenfileira(fila, &valor);
        if (valor % 2 == 0) enfileira(valor, par);
        else enfileira(valor, impar);
    }
    
    printf("Fila par: ");
    mostrar_fila(par);
    printf("\n");
    printf("Fila impar: \n");
    mostrar_fila(impar);
    return 1;
}

// int juntar_filas (t_fila *f1, t_fila *f2){
//     if(fila_vazia(f1) || fila_vazia(f2)) return 0;
//     int valor;
//     int tamanho_f2 = f2->ocupacao;  // Guarda o tamanho original de f2
//     if (f1->ocupacao <= f2->ocupacao){
//         desenfileira(f1, &valor);
//         enfileira(valor, f2);
//     }else{
//         desenfileira(f2, &valor);
//         enfileira(valor, f1);
//     }
//     return 1;
// }

int juntar_filas(t_fila *f1, t_fila *f2) {
    if (fila_vazia(f1) && fila_vazia(f2)) return 0;
    t_fila *menor, *maior;
    // Define qual é a menor e maior fila
    if (f1->ocupacao <= f2->ocupacao) {
        menor = f1;
        maior = f2;
    } else {
        menor = f2;
        maior = f1;
    }
    int valor;
    int tamanho = menor->ocupacao;
    for (int i = 0; i < tamanho; i++) {
        if (desenfileira(menor, &valor) == 0) return 0;
        if (enfileira(valor, maior) == 0) { // if como forma de return
            printf("Erro: fila maior sem espaço para juntar.\n");
            return 0;
        }
    }
    return 1;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//  O último elemento válido exige um pequeno "trabalho extra", 
//  porque fila->ultimo aponta para a próxima posição livre, 
//  não para o último valor.