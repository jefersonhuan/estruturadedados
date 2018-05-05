#include <stdio.h>
#include <stdlib.h>

struct lst {
  int valor;
  struct lst *ant;
  struct lst *prox;
};

typedef struct lst lista;

lista *prim, *atual, *ult;

int maxValor = 6;

void adicionarValor(int valor) {
  atual = malloc(sizeof(lista));
  atual->valor = valor;

  if(prim == NULL) {
    prim = atual;
  } else {
    ult->prox = atual;
    atual->ant = ult;
    atual->prox = prim;
    prim->ant = atual;
  }

  ult = atual;
}

void gerarLista() {
  for(int n = 0; n < maxValor; n++)  {
    adicionarValor(n);
  }
}

void listar() {
  atual = prim;
  int n = 0;

  while(1) {
    printf("%d: %d\n", n, atual->valor);
    n++;

    if(atual->prox == prim) break;

    atual = atual->prox;
  }
}

void remover(lista *no) {
  printf("Assassinando %d...\n", no->valor);

  no->ant->prox = no->prox;
  no->prox->ant = no->ant;

  if(no == prim) prim = prim->prox;

  free(no);
}

void limpar() {
  atual = prim;
  while(1) {
    ult = atual;
    free(ult);

    if(atual->prox == prim) break;
    atual = atual->prox;
  }

  exit(1);
}

int main() {
  printf("Inicializando lista com 41 nós...");

  gerarLista();

  printf("Lista gerada: \n");
  listar();

  atual = prim->prox->prox;

  while(1) {
    ult = atual;
    atual = atual->prox->prox;
    remover(ult);

    if(prim->prox == prim) break;
  }

  printf("Sobrou: \n");
  listar();

  limpar();

  return 0;
}
