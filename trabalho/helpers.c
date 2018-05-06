#include "helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int paraInt(char *valor) {
    return strtol(valor, NULL, 10);
}

int validaNibble(char *valor) {
    int n = 0;

    if(strlen(valor) != NIB)
        return 0;

    for(n; n < NIB; n++)
        if(valor[n] != '1' && valor[n] != '0')
            return 0;
}

int paraValorPositivo(int op, char a, char b) {
    switch(op) {
        case 5: // operacao XOR
            return a != b;
        case 6: // operacao OR
            return a == '1' || b == '1';
        case 7: // operacao AND
            return a == '1' && b == '1';
        default:
            return 0;
    }
}