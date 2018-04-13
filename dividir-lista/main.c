#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct lst {
    int valor;
    struct lst *prox;
};

typedef struct lst lista;

lista *prim, *prim2, *prim3, *atual, *ult;

int max = 6;
int elPorLista = 6/3;

lista *inicializa();
lista *divideLista(lista *init, int n);
void mostraLista(lista *pt);

int main() {
    srand((time) NULL);

    int n = 0;
    for(n; n < max; n++) {
        atual = inicializa();

        atual->valor = rand() % 20 + 1;

        printf("%dº elemento: %d\n", n, atual->valor);

        if(prim == NULL)
            prim = atual;
        else
            ult->prox = atual;

        atual->prox = NULL;
        ult = atual;
    }

    // elPorLista = em caso hipótetico de modularização
    prim2 = divideLista(prim, elPorLista);

    prim3 = divideLista(prim2, elPorLista);

    printf("Lista 1\n");
    mostraLista(prim);

    printf("Lista 2\n");
    mostraLista(prim2);

    printf("Lista 3\n");
    mostraLista(prim3);

    return 0;
}

lista *inicializa() {
    lista *t = malloc(sizeof(lista));

    if(t == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    } else
        return t;
}

lista *divideLista(lista *init, int n) {
    atual = init;

    while(atual->prox != NULL && n > 0) {
        ult = atual;
        atual = atual->prox;
        n--;
    }

    ult->prox = NULL;
    return atual;
}

void mostraLista(lista *pt) {
    atual = pt;

    while(atual != NULL) {
        ult = atual;
        printf("%d\n", atual->valor);

        atual = atual->prox;
        free(ult);
    }
}