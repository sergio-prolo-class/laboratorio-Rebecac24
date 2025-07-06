#include <stdio.h>

int main()
{
    float altura, largura, profundidade;
    float volume, area;
    int num_caixas;
    float custo_m2;

    printf("Entre com a altura (m): ");
    scanf("%f", &altura);  // Leia altura
    printf("Entre com a largura (m): ");
    scanf("%f", &largura);  // Leia largura
    printf("Entre com a profundidade (m): ");
    scanf("%f", &profundidade);  // Leia profundidade

    volume = altura * largura * profundidade;
    area = 2 * (altura * largura + largura * profundidade + profundidade * altura);

    // Escreva volume, area
    printf("A área é %g m² e o volume é %g m³\n", area, volume);

    printf("Entre com a quantidade de caixas: ");
    scanf("%d", &num_caixas);  // Leia num_caixas
    printf("Entre o custo do m² (R$): ");
    scanf("%f", &custo_m2);  // Leia custo_m2

    // Escreva num_caixas * area * custo_m2
    printf("Custo total: R$ %.2f\n", num_caixas * area * custo_m2);

    return 0;
}
