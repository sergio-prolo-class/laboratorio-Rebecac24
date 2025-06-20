#include <stdio.h>

int main()
{
    int numero, soma, digito;
    printf("Entre com um inteiro não-negativo: ");
    scanf("%d", &numero);
    while (numero > 0) {
        digito = numero % 10;
        numero = numero / 10;
        soma = soma + digito;
    }
    printf("Soma dos dígitos: %d", soma);
    return 0;
}