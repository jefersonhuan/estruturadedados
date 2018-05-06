#include <stdio.h>
#include <time.h>

int pilha[10];
int indice = -1;

void push(int valor) {
  pilha[++indice] = valor;
}

void pop() {
  indice--;
}

void mostarPilha() {
  for(;indice > -1;) {
    printf("%d: %d\n", indice, pilha[indice]);
    pop();
  }
}

int main() {
  srand((time) NULL);

  printf("Gerando pilha com dez elementos\n");

  for(int n = 0; n < 10; n++) {
    push(rand() % 100 + 1);
  }

  mostarPilha();
}
