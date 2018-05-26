#ifndef TRABALHO_HELPERS_H
#define TRABALHO_HELPERS_H

#define NIB 4
#define FLAG_TAM 3
#define INST_TAM 12

int validaNibble(int valor, int *receiver);
int arToInt(int *source, int tam);
void mostraArray(int *source, int tam);
int paraValorPositivo(int op, int a, int b);
int xor(int a, int b);
int and(int a, int b);
int or(int a, int b);

#endif //TRABALHO_HELPERS_H
