#include <stdio.h>

int main()
{
    // Variáveis
    float n1, n2, resultado;
    char operacao;

    printf("Entre com a expressão: ");
    scanf("%f %c %f", &n1, &operacao, &n2);

    switch (operacao) {
        case '+':
            resultado = n1 + n2;
            break;
        case '-':
            resultado = n1 - n2;
            break;
        case '*':
            resultado = n1 * n2;
            break;
        case '/':
            if (n2 == 0) {
                printf("Erro: Divisão por 0");
                return 1;
            }
            resultado = n1 / n2;
            break;
        default:
            printf("Erro: Operação desconhecida");
            return 1;
    }
    printf("%.2f\n", resultado);
    return 0;
}