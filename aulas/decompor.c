#include <stdio.h>
#include <stdlib.h>

char decompor(
    float x,
    int *parte_int,
    float *parte_frac)
{
}

int main()
{
    float numero, *parte_frac;
    int *parte_int;
    printf("Entre com número real: ");
    scanf("%f", &numero);
    char sinal = decompor(
        numero, &parte_int, &parte_frac);
    printf("Sinal: %c\n", sinal);
    printf("Parte inteira: %d\n", *parte_int)
}