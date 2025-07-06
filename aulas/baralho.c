#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_VALORES 13
#define NUM_NAIPES 4

int main()
{
    char valores[] = {'2', '3', '4', '5', '6', '8', '9', 'X', 'J', 'Q', 'K', 'A'};
    char naipes[] = {'e', 'c', 'o', 'o', 'p'};
    bool retirada[NUM_VALORES][NUM_NAIPES] = {};
    int num_cartas;
    int v, n;

    srand(time(NULL));

    printf("Entre com os números de cartas: ");
    scanf("%d", &num_cartas);

    printf("mão sorteada: ");
    while (num_cartas > 0) {
        v = rand() % NUM_VALORES;
        n = rand() % NUM_NAIPES;
        if (!retirada[v][n]) {
            printf(" %c%c", valores[v], naipes[n]);
            retirada[v][n] = true;
            num_cartas--;
        }
    }
    printf("\n");

    return 0;
}
