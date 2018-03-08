#include <stdio.h>

int tamVetor(int *v) {
  printf("%d\n", sizeof(v));
  return 0;
}

float mediaVetor(int *v, int n) {
  float media = 0;
  for(int i = 0; i < n; i++)
    media += v[i];

  return media/(float)n;
}

void varianciaVetor(int *v) {
}
