#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int dado1, dado2, num_rolagens, soma;
    float hist[11] = {};

    printf("Entre com o número de rolagens: ");
    scanf("%d", &num_rolagens);

    for (int i = 0; i < num_rolagens; i++) {
        dado1 = 1 + (rand() % 6);
        dado2 = 1 + (rand() % 6);
        soma = dado1 + dado2;
        hist[soma - 2] += 1;
    }

    for (int i = 0; i < 11; i++) {
        printf("%d : %.2f%%\n", i + 2, 100 * hist[i] / num_rolagens);
    }
    return EXIT_SUCCESS;
}