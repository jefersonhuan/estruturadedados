#include <stdlib.h>
#include <stdio.h>

void operacoes() {
     printf("S0\tS1\tS2\t: Operacao\n");
     printf("L\tL\tL\t: Clear\n");
     printf("L\tL\tH\t: B - A\n");
     printf("L\tH\tL\t: A - B\n");
     printf("L\tH\tH\t: A + B\n");
     printf("H\tL\tL\t: A XOR B\n");
     printf("H\tL\tH\t: A OU B\n");
     printf("H\tH\tL\t: A E B\n");
     printf("H\tH\tH\t: PRESET\n");
}

void menu() {
    int opcao;
    printf("1. Nova operacao\n2. Historico\n3. Remover oepração do historico\n4. Ordenar\n5. Tabela de operacoes\n0. Sair\n");
    printf("Sua opcao: ");
    scanf("%d", &opcao);

    switch(opcao) {
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
    printf("ULA");

    menu();
    return 0;
}