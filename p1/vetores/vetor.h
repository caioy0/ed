#include <stdio.h>
#include <math.h>

typedef struct {
    float x, y;
}ponto;

typedef struct {
    ponto c; //centro
    float raio;
}circulo;

typedef struct {
    int numerador;
    int denominador;
} fracao;