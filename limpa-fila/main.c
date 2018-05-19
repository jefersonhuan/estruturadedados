#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct stru {
  int id;
  struct stru *prox;
} fila;

fila *atual, *ult = NULL, *prim = NULL;

void esvaziar() {
  atual = prim;

  while(atual != NULL) {
    prim = prim->prox;
    printf("Removendo %d\n", atual->id);
    free(atual);
    atual = prim;
  }
}

void adicionar() {
  int n = rand() % 20;

  printf("Inserindo %d elementos...\n", n);

  for(int i = 0; i < n; i++) {
    atual = malloc(sizeof(fila));
    atual->id = rand() % 100 + 1;

    atual->prox = NULL;

    if(prim == NULL) {
      prim = atual;
    } else {
      ult->prox = atual;
    }

    ult = atual;
  }
}

void menu() {
  printf("1. Preencher fila\n2. Limpar fila\n0. Sair\n");
  printf("Sua opção: ");
  int opcao;
  scanf("%d", &opcao);

  switch (opcao) {
    case 1:
      adicionar();
      break;
    case 2:
      esvaziar();
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
  srand((time) NULL);
  menu();
}
