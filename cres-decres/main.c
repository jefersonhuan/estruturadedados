#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct lst {
    int valor;
    struct lst *prox;
};

typedef struct lst lista;

lista *prim, *atual, *ult;

lista *inicializa();
void geraLista(int nEl);

void mostraLista();

// alias
void ordemCres();
void ordemDecres();

void ordena(char tipo);

int main() {
    srand((time) NULL);

    int nEl;

    printf("Número de elementos da lista: ");
    scanf("%d", &nEl);

    printf("Gerando lista para ordem crescente\n");
    geraLista(nEl);
    ordemCres();

    mostraLista();

    printf("Gerando lista para ordem decrescente\n");
    geraLista(nEl);
    ordemDecres();

    mostraLista();

    return 0;
}

void ordemCres() {
    ordena('c');
}

void ordemDecres() {
    ordena('d');
}

void ordena(char tipo) {
    atual = ult = prim;

    int temp, troca = 0;

    while(atual != NULL) {
        if((tipo == 'c' && ult->valor > atual->valor) || (tipo == 'd' && ult->valor < atual->valor)) {
            temp = ult->valor;
            ult->valor = atual->valor;
            atual->valor = temp;
            troca = 1;
        }

        ult = atual;
        atual = atual->prox;

        if(troca) {
            atual = ult = prim;
            troca = 0;
        }
    }
}

lista *inicializa() {
    lista *t = malloc(sizeof(lista));

    if(t == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    } else
        return t;
}

void geraLista(int nEl) {
    for(int n = 0; n < nEl; n++) {
        atual = inicializa();

        atual->valor = rand() % 100 + 1;

        printf("%dº el: %d\n", n + 1, atual->valor);

        if(prim == NULL)
            prim = atual;
        else
            ult->prox = atual;

        atual->prox = NULL;
        ult = atual;
    }
}

void mostraLista() {
    printf("Lista ordenada:\n");

    atual = prim;

    while(atual != NULL) {
        ult = atual;
        printf("%d\n", atual->valor);
        atual = atual->prox;
        free(ult);
    }

    prim = NULL;
}