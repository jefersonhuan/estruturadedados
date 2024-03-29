#include <stdlib.h>
#include <stdio.h>
#include "operacoes.h"

void menu() {
    int opcao;
    printf("1. Nova instrucao\n2. Historico\n3. Remover operacao do historico\n4. Ordenar (resultado cres)\n5. Tabela de operacoes\n0. Sair\n");
    printf("Sua opcao: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            novaOp();
            break;
        case 2:
            mostraLista();
            break;
        case 3:
            remover();
        case 4:
            ordenar();
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