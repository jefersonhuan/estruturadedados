#include <stdio.h>
#include <stdlib.h>

typedef struct stru {
  char documento[60];
  int id;
  struct stru *prox;
} fila;

fila *atual, *ult = NULL, *prim = NULL;

void imprimir() {
  atual = prim;

  printf("Imprimindo documentos: \n");

  while(atual != NULL) {
    printf("Imprimindo trabalho %d, documento %s\n",
    atual->id, atual->documento);
    prim = prim->prox;
    free(atual);
    atual = prim;
  }
}

void adicionar() {
  atual = malloc(sizeof(fila));

  fflush(stdin);
  printf("Nome do documento: ");
  scanf("%s\0", &(atual->documento));

  printf("ID do documento: ");
  scanf("%d", &(atual->id));

  atual->prox = NULL;

  if(prim == NULL) {
    prim = atual;
  } else {
    ult->prox = atual;
  }

  ult = atual;
}

void menu() {
  printf("1. Adicionar documento\n2. Imprimir\n0. Sair\n");
  printf("Sua opção: ");
  int opcao;
  scanf("%d", &opcao);

  switch (opcao) {
    case 1:
      adicionar();
      break;
    case 2:
      imprimir();
      break;
    case 0:
      exit(1);
      break;
    default:
      printf("Opção inválida!\n");
  }

  menu();
}

int main() {
  menu();
}
