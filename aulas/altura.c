#include <stdio.h>
#include <math.h>
#define POL_POR_PE 12
#define CM_POR_POL 2.54

int main()
{
    // Variáveis
    int pes;
    int polegadas;
    float metros;
    // Início
    printf("Digite a altura em pés + polegadas (ex: 5 10): \n");
    scanf("%d%d", &pes, &polegadas);

    polegadas = pes * POL_POR_PE + polegadas;
    metros = polegadas * CM_POR_POL / 100;
    printf("Altura em metros: %.2f/n", metros);
    // Fim
    return 0;
}