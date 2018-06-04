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

int binParaComp[] = { 0, 0, 0, 1 };

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

int sum(int p[NIB], int q[NIB], int cin) {
    int n, carryOut = cin;
    int a, b;

    for(n = NIB - 1; n >= 0; n--) {
        a = p[n];
        b = q[n];

        atual->resultado[n] = ((a ^ b) ^ carryOut);
        carryOut = ((a & b) | (a & carryOut)) | (b & carryOut);
    }

    return carryOut;
}

void invert(int val[]) {
    int n;
    for(n = 0; n < NIB; n++) atual->resultado[n] = !val[n];
}

void bMinusA() {
    invert(atual->a);
    sum(atual->resultado, binParaComp, 0);
    sum(atual->b, atual->resultado, atual->cin);
}

void aMinusB() {
    invert(atual->b);
    sum(atual->resultado, binParaComp, 0);
    sum(atual->a, atual->resultado, atual->cin);
}

void aPlusB() {
    atual->ovr = sum(atual->a, atual->b, atual->cin);
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
    }
}

void mostraAtual() {
    printf("----------------\n");

    printf("A: ");
    mostraArray(atual->a, NIB);
    printf("\t");

    printf("B: ");
    mostraArray(atual->b, NIB);
    printf("\n");

    printf("Flag: ");
    mostraArray(atual->flag, FLAG_TAM);
    printf("\t");

    printf("CIN: %d\n", atual->cin);

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

    int count = 0;

    while(atual != NULL) {
        printf("\n");
        count++;
        printf("%dº registro: \n", count);
        mostraAtual();
        atual = atual->prox;
    }

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
        case 0:
            preenche(0);
            break;
        case 1:
            bMinusA();
            break;
        case 10:
            aMinusB();
            break;
        case 11:
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

    atual->prox = NULL;

    ult = atual;
}

void remover() {
    mostraLista();

    int reg, count, enc = 0;
    printf("Digite o número do registro a ser removido: ");
    scanf("%d", &reg);

    count = 0;
    atual = prim;

    while(atual != NULL) {
        count++;

        if(count == reg) {
            printf("Registro encontrado!\n");
            if(atual->ant != NULL) atual->ant->prox = atual->prox;
            if(atual->prox != NULL) atual->prox->ant = atual->ant;
            enc = 1;

            if(prim == atual) prim = atual->prox;

            free(atual);

            printf("Registro removido com sucesso!\n");

            break;
        }

        atual = atual->prox;
    }

    if(!enc) printf("Registro não encontrado\n");
}

void ordenar() {
    int troca = 0;
    int a, b;

    while(atual != NULL) {
        a = arToInt(atual->resultado, NIB);
        b = arToInt(ult->resultado, NIB);

        if(b > a) {
            ult->ant->prox = atual;
            atual->ant = ult->ant;



            troca = 1;
        }

        ult = atual;
        atual = atual->prox;

        if(troca) {
            atual = ult = prim;
            troca = 0;
        }
    }
}