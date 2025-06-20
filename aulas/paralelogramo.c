#include <stdio.h>
#include <math.h>

typedef struct {
    float lado_a;
    float lado_b;
    float angulo;
} Paralelogramo;

int main()
{
    Paralelogramo medidas;
    float area, perimetro;

    printf("Entre com os lados: ");
    scanf("%f %f", &medidas.lado_a, &medidas.lado_b);

    printf("Entre com o ângulo (graus): ");
    scanf("%f", &medidas.angulo);

    perimetro = 2 * (medidas.lado_a + medidas.lado_b);
    printf("perimetro %.2f/n", perimetro);

    area = medidas.lado_a * medidas.lado_b * sin(medidas.angulo * 3.1415 / 180);
    printf("Area %.2f\n", area);

    return 0;
}