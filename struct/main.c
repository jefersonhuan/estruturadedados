#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "func.h"

int main() {
  srand((time) NULL);
  ponto a, b;

  initPonto(&a);
  initPonto(&b);

  printf("%f\n", distanciaEuclid(a, b));

  return 0;
}
