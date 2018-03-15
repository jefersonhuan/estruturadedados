#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "func.h"

struct pto {
    float x, y, z;
};

ponto *preenche() {
    ponto *p = malloc(sizeof(ponto));

    if(p == NULL) {
        printf("Sem memória, fio");
        exit(1);
    }

    p->x = rand() % 20 + 1;
    p->y = rand() % 20 + 1;
    p->z = rand() % 20 + 1;
}

void acessa(ponto *p, float *x, float *y, float *z) {
    *x = p->x;
    *y = p->y;
    *z = p->z;
}

float distancia(ponto *a, ponto *b) {
    return sqrt(distanciaMan(a, b));
}

float distanciaMan(ponto *a, ponto *b) {
  return pow((a->x - b->x), 2) + pow((a->y - b->y), 2) + pow((a->z - b->z), 2);
}

void libera(ponto *p) {
    free(p);
}
