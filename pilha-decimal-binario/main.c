#include <stdio.h>
#include <stdlib.h>

typedef struct plh {
  int bin;
  struct plh *prox;
} pilha;

pilha *prim, *atual, *prox;

int vazia() {
  return prim == NULL;
}

void pop() {
  atual = prim;
  prox = atual->prox;
  free(atual);
  prim = prox;
}

int converter(int valor) {
  atual = malloc(sizeof(pilha));

  for(; valor )

  atual->bin = valor;

  if(prim != NULL)
    atual->prox = prim;
  else
    atual->prox = NULL;

  prim = atual;
}

void desempilhar() {
  atual = prim;

  while(atual != NULL) {
    printf("%d", atual->bin);
    pop();
    atual = prim;
  }

  printf("\n");
}

int main() {
  int dec;
  printf("Valor a ser convertido: ");
  scanf("%d", &dec);

  converter(dec);

  desempilhar();
}
