#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct stru {
    int valor;
    struct stru *prox;
} fila;

fila *atual, *ult, *prim = NULL, *prim2 = NULL, *primFinal = NULL;

int preencheFila(fila *p) {
    int n = rand() % 20 + 1;

    for(int i = 0; i < n; i++) {
        atual = malloc(sizeof(fila));

        atual->valor = rand() % 100 + 1;
        atual->prox = NULL;

        if(p == NULL) p = atual;
        else ult->prox = p;

        ult = p;
    }

    return n;
}

int main() {
    srand((time) NULL);

    int total = preencheFila(prim);
    int total2 = preencheFila(prim2);




    return 0;
}