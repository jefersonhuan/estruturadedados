#include <stdio.h>
#include <stdlib.h>

struct lst {
  int valor;
  struct lst *prox;
};

typedef struct lst lista;

lista *prim, *atual, *ult, *fim, *p, *q;

int cnt = 0;

void criarNo(int esp) {
  atual = malloc(sizeof(lista));

  printf("Valor do nó: ");
  scanf("%d", &(atual->valor));

  if(prim == NULL) {
    prim = atual;
  } else {
    if(esp) {
      int pos, n;
      printf("Índice do nó: ");
      scanf("%d", &pos);

      p = prim;
      n = 0;
      while(1) {
        if(pos == n) {
          if(n == 0) {
            atual->prox = prim;
            prim = atual;
            fim->prox = atual;
          } else if(cnt == n) {
            q->prox = atual;
            atual->prox = fim->prox;
            fim = atual;
          } else {
            q->prox = atual;
            atual->prox = p;
          }

          break;
        }

        if(p->prox == prim) break;

        q = p;
        p = p->prox;

        n++;
      }
    } else {
      ult->prox = atual;
      atual->prox = prim;
    }
  }

  ult = atual;
  fim = ult;
  cnt++;
}

void inserir() {
  printf("Número de nós: ");
  int nos;
  scanf("%d", &nos);

  for(int n = 0; n < nos; n++)  {
    criarNo(0);
  }
}

void listar() {
  atual = prim;
  int n = 0;
  while(1) {
    printf("%d: %d\n", n, atual->valor);

    if(atual->prox == prim) break;
    atual = atual->prox;
    n++;
  }
}

void removerNo(char tipo) {
  if(tipo == 'n')
    printf("Digite o nó a ser removido: ");
  else
    printf("Digite o valor a ser removido: ");


  int no, n;
  scanf("%d", &no);

  atual = prim;
  n = 0;
  while(1) {
    if(no == n) {
      if(prim == atual)  {
        prim = atual->prox;
        fim->prox = prim;
      } else if(atual == fim) {
        fim = ult;
        fim->prox = prim;
      } else {
        ult->prox = atual->prox;
      }

      free(atual);
      break;
    }

    if(atual->prox == NULL) break;
    ult = atual;
    atual = atual->prox;
    n++;
  }
}

void remover() {
  listar();

  printf("Remover por nó ou valor? \n1. Por nó\n2. Por valor\n");
  int opcao;
  scanf("%d", &opcao);

  switch(opcao) {
    case 1:
      removerNo('n');
      break;
    case 2:
      removerNo('v');
      break;
    default:
      printf("Opção inválida!\n");
      remover();
      break;
  }
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

void menu() {
  printf("1. Inserir nós\n2. Inserir nó\n3. Remover nó\n4. Imprimir lista\n0. Sair\n");
  printf("Sua opção: ");
  int opcao;

  scanf("%d", &opcao);

  switch(opcao) {
    case 1:
      inserir();
      break;
    case 2:
      criarNo(1);
      break;
    case 3:
      remover();
      break;
    case 4:
      listar();
      break;
    case 0:
      limpar();
      break;
    default:
      printf("Opção inválida!\n");
      break;
  }

  menu();
}

int main() {
  menu();

  return 0;
}
