#include <stdio.h>

int main()
{
    float imc, alt, peso;

    printf("Entre com o peso (kg):");
    scanf("%f", &peso);
    printf("Entre com a altura (m):");
    scanf("%f", &alt);

    imc = peso / (alt * alt);

    printf("IMC: %.2f kg/m²\n", imc);

    printf("Classificação:");
    if (imc < 18.5) {
        printf("Magreza");
    } else if (imc < 25.0) {
        printf("Normal");
    } else if (imc < 30.0) {
        printf("Sobrepeso");
    } else if {
        printf("Obesidade");
    }
    return 0;
}