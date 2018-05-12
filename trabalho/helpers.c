#include "helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int paraInt(char *valor) {
    return strtol(valor, NULL, 10);
}

void carregaResultado(int *valor) {
    int n;
    for(n = 0; n < NIB; n++) {
        *valor = *valor + conv.resultado[n] * (int)pow(10, n);
    }
}

int validaNibble(int valor, int *receiver) {
    int count = 0, temp = valor;

    while(valor != 0) {
        temp = valor % 10;
        valor /= 10;

        receiver[count] = temp;

        if(temp != 1 && temp != 0) return 0;

        count++;
    }

    if(count > 4) return 0;
}

int xor(int a, int b) {
    return a ^ b;
}

int and(int a, int b) {
    return a & b;
}

int or(int a, int b) {
    return a | b;
}

int paraValorPositivo(int op, int a, int b) {
    switch(op) {
        case 5: // operacao XOR
            return xor(a, b);
        case 6: // operacao OR
            return or(a, b);
        case 7: // operacao AND
            return and(a, b);
        default:
            return 0;
    }
}