#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct lst {
    int valor;
    struct lst *prox;
};

typedef struct lst lista;

lista *prim, *prim2, *atual, *ult;

lista *inicializa();
void mostraLista(lista *pt);
void geraLista(lista *pt);

int main() {
    srand((time) NULL);

    printf("Lista 1\n");
    geraLista(*prim);

    printf("Lista 2\n");
    geraLista(*prim2);

    atual = prim;
    while(atual != NULL) {
      if(atual->prox == NULL) {
          atual->prox = prim2;
          break;
      }

      atual = atual->prox;
    }

    printf("Lista final:\n");
    mostraLista(prim);

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

void geraLista(lista *pt) {
    for(int n = 0; n < 6; n++) {
        atual = inicializa();

        atual->valor = rand() % 100 + 1;

        printf("%dº el: %d\n", n + 1, atual->valor);

        if(pt == NULL)
            pt = atual;
        else
            ult->prox = atual;

        atual->prox = NULL;
        ult = atual;
    }
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
