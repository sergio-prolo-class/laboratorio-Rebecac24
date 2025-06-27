#include <stdio.h>
#include <stdbool.h>

bool eh_triangular(int n)
{
    // define se é triangular
    int i = 1;
    int soma = 0;
    while (soma < n) {
        soma = soma + i;
        i++;
    }
    return soma == n;
}

int main()
{
    int numero;
    printf("Entre com um inteiro positivo:");
    scanf("%d", &numero);
    if (numero < 1) {
        return 0;
    }
    if (eh_triangular(numero)) {
        printf("É triangular.\n");
    } else {
        printf("Não é triangular.\n");
    }
    return 0;
}