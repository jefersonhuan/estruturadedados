#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct lst {
    int valor;
    struct lst *prox;
} lista;

lista *prim, *atual, *ult;

lista *inicializa();
lista *menorValor();

int main() {
    srand((time) NULL);

    int nEl;
    printf("Número de elementos da lista: ");
    scanf("%d", &nEl);

    for(int n = 0; n < nEl; n++) {
        atual = inicializa();

        atual->valor = rand() % 100 + 1;

        printf("%d: %d\n", n + 1, atual->valor);

        if(prim == NULL)
            prim = atual;
        else
            ult->prox = atual;

        atual->prox = NULL;
        ult = atual;
    }

    printf("O menor valor é: %d\n", menorValor()->valor);

    atual = prim;

    while(atual != NULL) {
        ult = atual;
        atual = atual->prox;
        free(ult);
    }

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

lista *menorValor() {
    lista *menor;
    atual = menor = prim;

    while(atual != NULL) {
        if(atual->valor < menor->valor)
            menor = atual;

        atual = atual->prox;
    }

    return menor;
}