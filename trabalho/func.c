#include "func.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct op {
    int p, q, resultado, flag;
    struct op *prox;
    struct op *ant;
};

operacao *atual, *ult, *prim;

int flags[] = { 000, 001, 010, 011, 100, 101, 110, 111 };

char *paraString(int valor) {
    char str[5];
    sprintf(str, "%d", valor);
    return str;
}

void operacoes() {
    printf("1. LLL: Clear\n");
    printf("2. LLH: B - A\n");
    printf("3. LHL: A - B\n");
    printf("4. LHH: A + B\n");
    printf("5. HLL: A XOR B\n");
    printf("6. HLH: A OU B\n");
    printf("7. HHL: A E B\n");
    printf("8. HHH: PRESET\n");
}

void clear() {
    atual->resultado = 0000;
}

void preset() {
    atual->resultado = 1111;
}

int validaNibble(int valor) {
    int n = 0;

    char valorStr[10]; // evitar overflow
    sprintf(valorStr, "%d", valor);

    if(strlen(valorStr) != 4)
        return 0;

    for(n; n < 4; n++)
        if(valorStr[n] != '1' && valorStr[n] != '0')
            return 0;
}

void mostraAtual() {
    printf("----------------\n");
    printf("P: %04d\t", atual->p);
    printf("Q: %04d\n", atual->q);

    printf("Flag: %03d\n", atual->flag);
    printf("Resultado: %04d\n", atual->resultado);
}

void mostraLista() {
    atual = prim;

    do {
        mostraAtual();
        atual = atual->prox;
    } while(atual != prim);

    printf("\n");
}

void novaOp() {
    atual = malloc(sizeof(operacao));

    int opcao;
    int correto = 1;

    printf("Valores: \n");
    printf("[Os valores devem possuir exatamente 4 bits]\n");

    do {
        printf("Valor P: ");
        scanf("%d", &(atual->p));
    } while(!validaNibble(atual->p));

    do {
        printf("Valor Q: ");
        scanf("%d", &(atual->q));
    } while(!validaNibble(atual->q));

    printf("\n");

    do {
        correto = 1;

        operacoes();
        printf("Digite a operacao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                clear();
                break;
            case 8:
                preset();
                break;
            default:
                printf("Opcao invalida! Tente novamente!\n");
                correto = 0;
                break;
        }
    } while(!correto);

    atual->flag = flags[opcao - 1];

    printf("Resultado: \n");
    mostraAtual();
    printf("\n");

    if(prim == NULL)
        prim = atual;
    else {
        atual->ant = ult;
        ult->prox = atual;
    }

    atual->prox = prim;
    prim->ant = atual;

    ult = atual;
}