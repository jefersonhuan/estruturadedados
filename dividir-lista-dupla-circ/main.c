#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct lst {
    int valor;
    struct lst *ant;
    struct lst *prox;
};

typedef struct lst lista;

lista *prim, *prim2, *atual, *ult;

lista *inicializa();
lista *divideLista(lista *init, int n);
void mostraLista(lista *pt);

int main() {
    srand((time) NULL);

    int n = 0;
    for(n; n < 10; n++) {
        atual = inicializa();

        atual->valor = rand() % 20 + 1;

        printf("%dº elemento: %d\n", n, atual->valor);

        if(prim == NULL) {
          prim = atual;
        } else {
          atual->ant = ult;
          ult->prox = atual;
        }

        prim->ant = atual;
        atual->prox = prim;

        ult = atual;
    }

    printf("Lista inicial: \n");
    mostraLista(prim);

    int elPorLista;
    printf("Dividir lista a partir de: ");
    scanf("%d", &elPorLista);

    prim2 = divideLista(prim, elPorLista);

    printf("Lista 1\n");
    mostraLista(prim);

    printf("Lista 2\n");
    mostraLista(prim2);

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

    while(n > 1) {
      ult = atual;

      if(atual->prox == init) break;
      atual = atual->prox;
      n--;
    }

    ult->prox = init;
    init->ant = ult;

    return atual;
}

void mostraLista(lista *pt) {
    atual = pt;

    int n = 0;
    do {
      n++;
      ult = atual;
      printf("%d: %d\n", n, atual->valor);

      atual = atual->prox;
    } while(atual != prim);
}
