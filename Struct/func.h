struct pto {
  float x, y;
};

typedef struct pto ponto;

float distanciaEuclid(ponto a, ponto b);
void initPonto(ponto *coord);
