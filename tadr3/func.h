typedef struct pto ponto;

ponto *preenche();
void acessa(ponto *p, float *x, float *y, float *z);
float distancia(ponto *a, ponto *b);
float distanciaMan(ponto *a, ponto *b);
void libera(ponto *p);
