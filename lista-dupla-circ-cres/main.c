#include <stdio.h>
#include <stdlib.h>

struct lst {
  int valor;
  struct lst *ant;
  struct lst *prox;
};

typedef struct lst lista;

lista *prim, *atual, *ult;

void inserirValores() {
  while(1) {
    int valor;

    printf("Digite o valor [-1 para parar]: ");
    scanf("%d", &valor);
    if(valor == -1) break;

    atual = malloc(sizeof(lista));
    atual->valor = valor;

    if(prim == NULL) {
      prim = atual;
    } else {
      ult->prox = atual;
      atual->ant = ult;
    }

    prim->ant = atual;
    atual->prox = prim;
    ult = atual;
  }
}

void listar() {
  atual = prim;
  int n = 0;

  do {
    printf("%d: %d\n", n, atual->valor);
    n++;

    atual = atual->prox;
  } while(atual != prim);
}

void limpar() {
  atual = prim;
  do {
    ult = atual;
    free(ult);

    atual = atual->prox;
  } while(atual != prim);

  exit(1);
}

int ordena() {
  atual = ult = prim;

  int temp, troca = 0;

  do {
    if(ult->valor > atual->valor) {
      temp = ult->valor;
      ult->valor = atual->valor;
      atual->valor = temp;
      troca = 1;
    }

    ult = atual;
    atual = atual->prox;
  } while(atual != prim);

  if(troca) ordena();
}

int main() {
  inserirValores();

  ordena();

  listar();

  return 0;
}
