#include <stdio.h>
#include "oo.h"
#include "pessoa.h"
#include "cachorro.h"
#include "gato.h"

int main() {
    void* obj1 = criar_pessoa("Ana", 27);
    void* obj2 = criar_cachorro("Rex");
    void* obj3 = criar_gato("Luna");

    Objeto* objetos[] = {
        &((Pessoa*)obj1)->base,
        &((Cachorro*)obj2)->base,
        &((Gato*)obj3)->base
    };

    void* reais[] = { obj1, obj2, obj3 };

    for (int i = 0; i < 3; i++) {
        identificar_objeto(objetos[i]);
        objetos[i]->falar(reais[i]);
        objetos[i]->comer(reais[i]);
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        objetos[i]->destruir(reais[i]);
    }

    return 0;
}
