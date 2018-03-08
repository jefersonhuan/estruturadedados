#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

int main() {
  int n = 7;
  int v[n];

  srand((time) NULL);

  for(int i = 0; i < n; i++) {
      v[i] = rand() % 100 + 1;
      printf("%d: %d\n", i, v[i]);
  }

  printf("%d\n", tamVetor(v));
  return 0;
}
