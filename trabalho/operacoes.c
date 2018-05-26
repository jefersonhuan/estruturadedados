#include "operacoes.h"
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>

struct op {
    int a[NIB], b[NIB], resultado[NIB], flag[FLAG_TAM], cin, ovr;
    struct op *prox;
    struct op *ant;
};

operacao *atual, *ult, *prim;

int flags[] = { 000, 001, 010, 011, 100, 101, 110, 111 };

void operacoes() {
    printf("000: Clear\n");
    printf("001: B - A\n");
    printf("010: A - B\n");
    printf("011: A + B\n");
    printf("100: A XOR B\n");
    printf("101: A OU B\n");
    printf("110: A E B\n");
    printf("111: PRESET\n");
}

void preenche(int bit) {
    int n;
    for(n = 0; n < NIB; n++) atual->resultado[n] = bit;
}

void bMinusA() {

}

void aMinusB() {
}

void aPlusB() {
    int n, carryOut = 0;

    for(n = 0; n < NIB; n++) {
        atual->resultado[n] = xor(atual->a[n], atual->b[n]);
        carryOut = and(atual->a[n], atual->b[n]);

        if(carryOut) {
            atual->resultado[n] = 0;

            if(n != NIB - 1) {
                int next = n + 1;
                atual->a[next] = xor(atual->a[next], 1);
            }
        }
    }

    atual->ovr = carryOut;
}

void bitPorBit(int op) {
    int n;

    for(n = 0; n < NIB; n++)
        atual->resultado[n] = paraValorPositivo(op, atual->a[n], atual->b[n]);
}

int validaInstrucao(long int valor) {
    int count = 0;
    long int temp;

    while(valor != 0) {
        temp = valor % 10;
        valor /= 10;

        if(temp != 1 && temp != 0) return 0;

        if(count == 0)
            atual->cin = temp;
        else if(count > 0 && count <= 3)
            atual->flag[FLAG_TAM - count] = temp;
        else if(count > 3 && count <= 7)
            atual->b[(NIB + 3) - count] = temp;
        else if(count > 7 && count <= 11)
            atual->a[(NIB + 7) - count] = temp;
        else
            return 0;

        count++;

        if(count > INST_TAM) return 0;
    }
}

void mostraAtual() {
    printf("----------------\n");

    printf("A:");
    mostraArray(atual->a, NIB);
    printf("\t");

    printf("B:");
    mostraArray(atual->b, NIB);
    printf("\t");

    printf("Flag:");
    mostraArray(atual->flag, FLAG_TAM);
    printf("\n");

    printf("Resultado: ");
    mostraArray(atual->resultado, NIB);
    printf("\n");

    printf("Overflow: %d\n", atual->ovr);
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
    atual->ovr = 0;

    int opcao = 0;

    long int inst;
    printf("Formato da instrução: NIBBLE-NIBBLE-FLAG-CIN\nSem o \"-\"\n");

    do {
        printf("Insira os bits da instrução: ");
        scanf("%ld", &inst);
    } while(!validaInstrucao(inst));

    printf("\n");

    opcao = arToInt(atual->flag, FLAG_TAM);

    switch(opcao) {
        case 000:
            preenche(0);
            break;
        case 001:
            bMinusA();
            break;
        case 010:
            aMinusB();
            break;
        case 011:
            aPlusB();
            break;
        case 100:
        case 101:
        case 110:
            bitPorBit(opcao);
            break;
        case 111:
            preenche(1);
            break;
        default:
            printf("Opcao invalida!\n");
            novaOp();
            break;
    }

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