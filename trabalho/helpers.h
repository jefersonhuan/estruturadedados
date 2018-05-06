#ifndef TRABALHO_HELPERS_H
#define TRABALHO_HELPERS_H

#define NIB 4

struct converter {
    char a[NIB + 1], b[NIB + 1], resultado[NIB + 1];
} conv;

int paraInt(char *valor);
int validaNibble(char *valor);
int paraValorPositivo(int op, char a, char b);

#endif //TRABALHO_HELPERS_H
