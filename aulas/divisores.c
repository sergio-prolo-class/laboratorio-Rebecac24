#include <stdio.h>

int main()
{
    int numero, divisores = 0;

    printf("Entre com um número inteiro positivo: ");
    scanf("%d", &numero);

    printf("Divisores: [1");
    int N_divisores = 1;
    for (int i = 2; i <= numero; i++) {
        if (numero % i == 0) {
            N_divisores++;
            printf(", %d", i);
        }
    }
    printf("]\n");

    printf("%s\n", (N_divisores == 2) ? "É primo" : "Não é primo");
    return 0;
}