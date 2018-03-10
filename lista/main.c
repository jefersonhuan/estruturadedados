#include <stdio.h>
#include <stdlib.h>

typedef struct lst {
    int id;
    struct lst *ant;
    struct lst *prox;
} lista;

lista *prim, *temp, *ult;

lista* inicializar() {
    malloc(sizeof(lista));
}

void inserir() {
    temp = inicializar();

    printf("Insira o ID: ");
    scanf("%d", &(temp->id));

    if(prim == NULL) {
        prim = temp;
    } else {
        ult->prox = temp;
        temp->ant = ult;
    }

    ult = temp;
}

void listar() {
    temp = prim;
    int cont = 1;

    while(temp != NULL) {
        printf("%d: %d\n", cont++, temp->id);
        temp = temp->prox;
    }
}

void remover() {
    listar();
    int indice;
    int cont = 1;
    printf("Digite o número do nó a ser removido: ");
    scanf("%d", &indice);

    temp = prim;
    while(temp != NULL) {
        if(cont == indice) {
            if(temp->prox != NULL) {
                ult->prox = temp->prox;
                free(temp);
            }
        } 
        
        cont++;
        ult = temp;
        temp = temp->prox;
    }

    printf("Lista atualizada: \n");
    listar();
}

void menu() {
    int opcao;
    printf("1. Inserir nó\n2. Listar\n3. Remover nó\n0. Sair\n");
    printf("Sua opção: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            inserir();
            break;
        case 2:
            listar();
            break;
        case 3:
            remover();
            break;
        case 0:
            exit(1);
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