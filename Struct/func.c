#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float distanciaEuclid(ponto a, ponto b) {
  return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

void initPonto(ponto *coord)  {
  srand((time) NULL);

  coord -> x = rand() % 20 + 1;
  coord -> y = rand() % 20 + 1;

  printf("Coor. X: %f\n", coord -> x);
  printf("Coor. Y: %f\n", coord -> y);
}
