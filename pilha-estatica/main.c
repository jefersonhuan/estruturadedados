#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct pilha {
  int valor[10];
  int topo;
} pilha;

int cheia() {
  return pilha.topo == MAX - 1;
}

int vazia() {
  return pilha.topo == -1;
}

void pop() {
  pilha.topo--;
}

int inserir() {
  if(cheia()) return 0;

  int valor;
  printf("Valor a ser inserido: ");
  scanf("%d", &valor);

  pilha.valor[++pilha.topo] = valor;
}

void desempilhar() {
  for(; pilha.topo > -1 ;) {
    printf("%d: %d\n", pilha.topo, pilha.valor[pilha.topo]);
    pop();
  }
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
  pilha.topo = -1;

  menu();
}
