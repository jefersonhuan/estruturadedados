#include "operacoes.h"
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>

struct op {
    int a, b, resultado, flag;
    struct op *prox;
    struct op *ant;
};

operacao *atual, *ult, *prim;

int flags[] = { 000, 001, 010, 011, 100, 101, 110, 111 };

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

void bMinusA() {

}

void aMinusB() {

}

void aPlusB() {

}

void bitPorBit(int op) {
    int n;

    for(n = 0; n < NIB; n++)
        if(paraValorPositivo(op, conv.a[n], conv.b[n]))
            conv.resultado[n] = '1';
        else
            conv.resultado[n] = '0';
}

void preset() {
    atual->resultado = 1111;
}

void mostraAtual() {
    printf("----------------\n");
    printf("A: %04d\t", atual->a);
    printf("B: %04d\n", atual->b);

    printf("Flag: %03d\n", atual->flag);
    printf("Resultado: %04d\n", atual->resultado);
}

void mostraLista() {
    atual = prim;

    if(atual == NULL) {
        printf("Nenhuma operacao encontrada\n");
        return;
    }

    do {
        mostraAtual();
        atual = atual->prox;
    } while(atual != prim);

    printf("\n");
}

void novaOp() {
    atual = malloc(sizeof(operacao));

    int opcao = 0;
    int correto;

    printf("Valores: \n");
    printf("[Os valores devem possuir exatamente 4 bits]\n");

    /*
     * o "conv", da struct converter (helpers.h) é utilizado
     * como intermediador apenas no momento das operações.
     */

    do {
        printf("Valor A: ");
        scanf("%s", &(conv.a));
    } while(!validaNibble(conv.a));

    atual->a = paraInt(conv.a);

    do {
        printf("Valor B: ");
        scanf("%s", &(conv.b));
    } while(!validaNibble(conv.b));

    atual->b = paraInt(conv.b);

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
            case 2:
                bMinusA();
                break;
            case 3:
                aMinusB();
                break;
            case 4:
                aPlusB();
                break;
            case 5:
            case 6:
            case 7:
                bitPorBit(opcao);
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
    atual->resultado = paraInt(conv.resultado);

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