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
    free(atual);
    atual = prim;
  }
}

void contarFila(fila *prim) {
  int count = 0;
  atual = prim;

  if(prim == NULL) printf("Nenhum requerimento encontrado\n");
  else {
    while(atual != NULL) {
      count++;
      atual = atual->prox;
    }
  }

  printf("Foram encontrados %d elementos\n", count);
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
  printf("1. Preencher fila\n2. Contar fila\n3. Limpar fila\n0. Sair\n");
  printf("Sua opção: ");
  int opcao;
  scanf("%d", &opcao);

  switch (opcao) {
    case 1:
      adicionar();
      break;
    case 2:
      contarFila(prim);
      break;
    case 3:
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
