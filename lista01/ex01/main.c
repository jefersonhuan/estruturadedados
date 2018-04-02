#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void menu() {
  printf("1. Inserir sequência\n2. Mostrar lista\n3. Adicionar nó\n4. Eliminar nó\n0. Sair\n");
  printf("Digite sua opção: ");
  int opcao;
  scanf("%d", &opcao);

  switch (opcao) {
    case 1:
      inserirSequencia();
      break;
    case 2:
      listar();
      break;
    case 3:
      inserirNo(0);
      break;
    case 4:
      removerNo();
      break;
    case 0:
      exit(0);
      break;
    default:
      printf("Opção inválida!\n");
  }

  menu();
}

int main() {
  menu();

  return 0;
}
