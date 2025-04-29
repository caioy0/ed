#include <stdio.h>
#include "oo.h"

void identificar_objeto(Objeto* obj) {
    switch (obj->tipo) {
        case TIPO_PESSOA:   printf("[RTTI] Pessoa\n"); break;
        case TIPO_CACHORRO: printf("[RTTI] Cachorro\n"); break;
        case TIPO_GATO:     printf("[RTTI] Gato\n"); break;
        default:            printf("[RTTI] Tipo desconhecido\n"); break;
    }
}
