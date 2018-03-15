#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "func.h"

int main() {
    srand((time) NULL);
    float x, y, z;

    ponto *a = preenche();
    ponto *b = preenche();

    acessa(a, &x, &y, &z);
    printf("Ponto A: %.2f, %.2f, %.2f\n", x, y, z);

    acessa(b, &x, &y, &z);
    printf("Ponto B: %.2f, %.2f, %.2f\n", x, y, z);

    printf("Distância: %.2f\n", distancia(a, b));

    printf("Distancia Manhattan: %.2f\n", distanciaMan(a, b));

    libera(a);
    libera(b);

    return 0;
}
