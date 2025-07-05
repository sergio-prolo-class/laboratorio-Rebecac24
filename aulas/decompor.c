#include <stdio.h>

char decompor(float x, int *parte_int, float *parte_frac);

int main()
{
    float x, pf;
    int pi;
    char s;
    printf("Entre com número real: ");
    scanf("%f", &x);
    s = decompor(x, &pi, &pf);
    printf("Sinal: %c\n", s);
    printf("Parte inteira: %d\n", pi);
    printf("Parte fracionada: %g\n", pf);
    return 0;
}

char decompor(float x, int *parte_int, float *parte_frac)
{
    char sinal;
    if (x > 0) {
        sinal = '+';
    } else if (x < 0) {
        x = -x;
        sinal = '-';
    } else {
        sinal = ' ';
    }
    *parte_int = (int)x;  // casting
    *parte_frac = x - *parte_int;
    return sinal;
}