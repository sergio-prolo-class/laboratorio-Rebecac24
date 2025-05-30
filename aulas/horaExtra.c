#include <stdio.h>

int main()
{
    // Variáveis
    float hrs, pag;
    // Escreva
    printf("Entre com as horas trabalhadas: ");
    scanf("%f", &hrs);
    pag = 50.0 * hrs;
    if (hrs > 8.0) {
        pag += 25 * (hrs - 8);
        // Se então
    }
    printf("Pagamento: %.2f\n, pag");
    // Fim
    return 0;
}