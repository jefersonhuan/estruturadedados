#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct pto {
  float x, y;
};

typedef struct pto ponto;

float distanciaEuclid(ponto a, ponto b);
void initPonto(ponto *coord);

int main() {
  srand((time) NULL);
  ponto a, b;

  initPonto(&a);
  initPonto(&b);

  printf("%f\n", distanciaEuclid(a, b));

  return 0;
}

float distanciaEuclid(ponto a, ponto b) {
  return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

void initPonto(ponto *coord)  {

  coord->x = rand() % 20 + 1;
  coord->y = rand() % 20 + 1;

  printf("Coor. X: %f\n", coord -> x);
  printf("Coor. Y: %f\n", coord -> y);
}
