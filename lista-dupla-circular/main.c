#include <stdio.h>
#include <stdlib.h>

struct lst {
    int valor;
    struct lst *ant;
    struct lst *prox;
};

typedef struct lst lista;

lista *prim, *atual, *ult, *fim, *p, *q;

void criarNo(int esp) {
    atual = malloc(sizeof(lista));

    printf("Valor do nó: ");
    scanf("%d", &(atual->valor));

    if(prim == NULL) {
        prim = atual;
    } else if(esp) {
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
                } else {
                    q->prox = atual;
                    atual->ant = q;
                    atual->prox = p;
                    p->ant = atual;
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
        atual->ant = ult;
        atual->prox = prim;
        prim->ant = atual;
    }

    ult = atual;
    fim = ult;
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

void listarContrario() {
    atual = prim->ant;
    int n = 0;

    while(1) {
        printf("%d: %d\n", n, atual->valor);

        if(atual == prim) break;
        atual = atual->ant;
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
        if((tipo == 'n' && no == n) || (tipo == 'v' && atual->valor == no)) {
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
    printf("Sua opção: ");
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
    printf("1. Inserir nós\n2. Inserir nó\n3. Remover nó\n4. Imprimir lista\n5. Imprimir lista (contrário)\n0. Sair\n");
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
        case 5:
            listarContrario();
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