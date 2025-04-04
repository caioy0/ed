#ifndef OO_FRAMEWORK_H
#define OO_FRAMEWORK_H

typedef enum {
    TIPO_PESSOA,
    TIPO_CACHORRO,
    TIPO_GATO
} TipoObjeto;

// Interface genérica
typedef struct Objeto {
    TipoObjeto tipo;

    void (*falar)(void *this);
    void (*comer)(void *this);
    void (*destruir)(void *this);
} Objeto;

// RTTI
void identificar_objeto(Objeto* obj);

#endif
