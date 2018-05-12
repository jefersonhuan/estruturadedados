#ifndef TRABALHO_HELPERS_H
#define TRABALHO_HELPERS_H

#define NIB 4

struct convenience {
    int a[NIB], b[NIB], resultado[NIB];
} conv;

int paraInt(char *valor);
int validaNibble(int valor, int *receiver);
int paraValorPositivo(int op, int a, int b);
int xor(int a, int b);
int and(int a, int b);
int or(int a, int b);
void carregaBinarios();
void carregaResultado(int *valor);

#endif //TRABALHO_HELPERS_H
