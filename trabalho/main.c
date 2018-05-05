#include <stdlib.h>
#include <stdio.h>
#include "func.h"

void menu() {
    int opcao;
    printf("1. Nova operacao\n2. Historico\n3. Remover operacao do historico\n4. Ordenar\n5. Tabela de operacoes\n0. Sair\n");
    printf("Sua opcao: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            novaOp();
            break;
        case 2:
            mostraLista();
            break;
        case 5:
            operacoes();
            break;
        case 0:
            exit(0);
        default:
            printf("Opcao invalida. Tente noavmente\n");
    }

    menu();
}

int main() {
    printf("ULA\n");

    menu();
    return 0;
}