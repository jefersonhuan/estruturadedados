#include <stdio.h>

int main() {
    int i = 0, j = 1, termo, temp;

    printf("Digite o termo final da sequência fibonacci: ");
    scanf("%d", &termo);

    for(int n = 0; n < termo; n++) {
        temp = i + j;

        printf("%d\t", temp);
        j = i;
        i = temp;
    }

    return 0;
}