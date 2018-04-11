#include "func.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct op {
    char *p, *q, *resultado, *flag;
    operacao* prox;
};

operacao *atual, *ult, *prim;

char flags[][4] = { "000", "001", "010", "011", "100", "101", "110", "111" };

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
    atual->resultado = "0000";
}

int validaNibble(char *valor) {
    int n = 0;

    if(strlen(valor) != 4)
        return 0;

    for(n; n < 4; n++)
        if(valor[n] != '1' && valor[n] != '0')
            return 0;
}

void mostraLista() {
    printf("----------------\n");
    printf("P: %s\t", atual->p);
    printf("Q: %s\n", atual->q);

    printf("Flag: %s\n", atual->flag);
    printf("Resultado: %s\n", atual->resultado);
}

void novaOp() {
    if(prim == NULL) {
        prim = malloc(sizeof(operacao));
        prim->p = prim->q = malloc(20 * sizeof(char));
        prim->flag = prim->resultado = malloc(4 * sizeof(char));
        atual = prim;
    }

    int opcao;
    int correto = 1;

    printf("Valores: \n");
    printf("[Os valores devem possuir exatamente 4 bits]\n");

    do {
        printf("Valor P: ");
        scanf("%s", atual->p);
    } while(!validaNibble(atual->p));

    do {
        printf("Valor Q: ");
        scanf("%s", atual->q);
    } while(!validaNibble(atual->q));

    printf("\n");

    do {
        operacoes();
        printf("Digite a operacao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                clear();
                break;
            default:
                printf("Opcao invalida! Tente novamente!\n");
                correto = 0;
                break;
        }
    } while(!correto);

    atual->flag = flags[opcao - 1];

    printf("Resultado: \n");
    mostraLista();
    printf("\n");

    if(ult != NULL)
        ult->prox = atual;

    ult = atual;
}