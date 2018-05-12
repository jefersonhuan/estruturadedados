#include "operacoes.h"
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>

struct op {
    int a, b, resultado, flag, cin, cn4;
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
    int n, carryOut = 0;

    for(n = 0; n < NIB; n++) {
        conv.resultado[n] = xor(conv.a[n], conv.b[n]);
        carryOut = and(conv.a[n], conv.b[n]);

        if(carryOut) {
            conv.resultado[n] = 0;

            if(n != NIB - 1) {
                int next = n + 1;
                conv.a[next] = xor(conv.a[next], 1);
            }
        }
    }

    atual->cn4 = carryOut;
}

void bitPorBit(int op) {
    int n;

    for(n = 0; n < NIB; n++)
        conv.resultado[n] = paraValorPositivo(op, conv.a[n], conv.b[n]);
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
    printf("Cn4: %d\n", atual->cn4);
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
    atual->cn4 = 0;

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
        scanf("%d", &(atual->a));
    } while(!validaNibble(atual->a, &(conv.a)));

    do {
        printf("Valor B: ");
        scanf("%d", &(atual->b));
    } while(!validaNibble(atual->b, &(conv.b)));

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
    carregaResultado(&(atual->resultado));

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