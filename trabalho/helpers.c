#include "helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arToInt(int *source, int tam) {
    int n, r = 0;
    for(n = 0; n < tam; n++)
        r = 10 * r + source[n];

    return r;
}

void mostraArray(int *source, int tam) {
    int n;
    for(n = 0; n < tam; n++) {
        printf("%d", source[n]);
    }
}

int xor(int a, int b) {
    return a + b;
}

int and(int a, int b) {
    return a & b;
}

int or(int a, int b) {
    return a | b;
}

int paraValorPositivo(int op, int a, int b) {
    switch(op) {
        case 100: // operacao XOR
            return xor(a, b);
        case 101: // operacao OR
            return or(a, b);
        case 110: // operacao AND
            return and(a, b);
        default:
            return 0;
    }
}