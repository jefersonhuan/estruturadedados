#include <stdlib.h>
#include <stdio.h>
#include "func.h"

typedef struct nmr {
  int valor;
  struct numero *prox;
} numero;

numero *inicia() {
  malloc(sizeof(numero));
}

numero *prim, *atual, *ult;

void inserirNo(int ignorarPosicao) {
  atual = inicia();
  int posicao = -1;

  printf("Insira o inteiro: ");
  scanf("%d", &(atual->valor));

  if(ignorarPosicao == 0) {
    printf("Posição do nó [-1 para final da lista]: ");
    scanf("%d", &posicao);
  }

  if(prim == NULL) {
    prim = atual;
  } else if(posicao != -1) {
      numero *p, *q;
      int indice = 0;

      p = prim;
      while(p != NULL) {
        indice++;
        if(posicao == indice) {
          if(posicao == 1) {
            prim = atual;
            prim->prox = p;
          } else {
            q->prox = atual;
            atual->prox = p;
          }

          break;
        }

        p = p->prox;
        q = p;
      }
  } else {
    ult->prox = atual;
  }

  if(posicao != -1) ult = atual;
}

void listar() {
  atual = prim;
  int cont = 0;

  while(atual != NULL) {
    cont++;
    printf("%d: %d\n", cont, atual->valor);

    atual = atual->prox;
  }

  printf("\n");
}

void inserirSequencia() {
  printf("Número de nós: ");
  int atual;
  scanf("%d", &atual);

  for(int n = 0; n < atual; n++) {
    inserirNo(1);
  }

  listar();
}

void removerNo() {
  listar();

  printf("Digite o endereço a ser removido: ");
  int indice = 0, remover;
  scanf("%d", &remover);

  atual = prim;
  while(atual != NULL) {
    indice++;
    if(remover == indice) {
      if(prim == atual) {
        prim = atual->prox;
      } else {
        ult->prox = atual->prox;
      }
    }

    ult = atual;
    atual = atual->prox;
  }

  listar();
}
