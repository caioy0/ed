#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int info;
    struct no * proximo;
}t_no;

t_no *constroi_no(int);