#include <stdio.h>

int main()
{
    int quant_chuva, quant_chuva_total = 0;
    for (int i = 1; i <= 7; i++) {
        printf("Entre com a quantidade de chuva no dia %i em litros: ", i);
        scanf("%d", &quant_chuva);
        quant_chuva_total += quant_chuva;

        if (quant_chuva_total >= 400) {
            printf("O reservatório transbordou no dia %i", i);
            break;
        }
        if (i == 7) {
            printf("O reservatório não transbordou. Espaço livre: %d litros.", 400 - quant_chuva_total);
        }
    }

    return 0;
}