#include <stdio.h>
#include <stdlib.h>

typedef struct plh {
  char c;
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

int inserir() {
  atual = malloc(sizeof(pilha));

  fflush(stdin);

  printf("Char a ser inserido: ");
  scanf("%s", &(atual->c));

  if(prim != NULL)
    atual->prox = prim;
  else
    atual->prox = NULL;

  prim = atual;
}

void desempilhar() {
  atual = prim;

  while(atual != NULL) {
    printf("%c", atual->c);
    pop();
    atual = prim;
  }

  printf("\n");
}

void menu() {
  printf("1. Inserir valor\n2. Desempilhar\n0. Sair\n");
  printf("Sua opção: ");
  int opcao;

  scanf("%d", &opcao);

  switch(opcao) {
    case 1:
      inserir();
      break;
    case 2:
      desempilhar();
      break;
    case 0:
      exit(1);
    default:
      printf("Opção inválida. Tente novamente\n");
      break;
  }

  menu();
}

int main() {
  menu();
}
