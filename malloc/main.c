#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int counter = 0;
  int *numeros = NULL;  

  int i;
  printf("Digite -1 para parar.\n");
  while(1) {
    printf("Digite um número: ");
    scanf("%d", &i);

    if(i == -1) break;

    numeros = (int*) realloc (numeros, (counter + 1) * sizeof(int));
    numeros[counter] = i;
    counter++;
  }

  printf("%d números inseridos.\n", counter);
  printf("Números em ordem inversa: \n");

  int n;
  for(n = counter - 1; n >= 0; n--)
    printf("%d: %d\n", n, numeros[n]);


  free(numeros);

  return 0;
}
