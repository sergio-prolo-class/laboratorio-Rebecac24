#include <stdio.h>
#include <math.h>

typedef struct {
    float x, y;
} Ponto;

void mover_ponto(Ponto *p, char direcao, float distancia)
{
    switch (direcao) {
        case 'N':
            (*p).y = (*p).y + distancia;
            break;

        case 'S':
            (*p).y = (*p).y - distancia;
            break;

        case 'L':
            (*p).x = (*p).x + distancia;
            break;

        case 'O':
            (*p).x = (*p).x - distancia;
            break;
    }
}

float calcular_distancia(Ponto p1, Ponto p2)
{
    return hypot(p2.x - p1.x, p2.y - p1.y);
}

int main()
{
    float distancia;
    char direcao;
    Ponto robo1 = {0, 0};
    Ponto robo2 = {10, 10};

    printf("Entre com os movimentos do robô 1:");

    for (int i = 1; i <= 3; i++) {
        scanf(" %c %f", &direcao, &distancia);
        mover_ponto(&robo1, direcao, distancia);
    }

    printf("Entre com os movimentos do robô 2: ");

    for (int i = 1; i <= 3; i++) {
        scanf(" %c %f", &direcao, &distancia);
        mover_ponto(&robo2, direcao, distancia);
    }

    printf("Posição final do robô 1: (%g, %g)\n", robo1.x, robo1.y);
    printf("Posição final do robô 2: (%g, %g)\n", robo2.x, robo2.y);
    printf("Distância entre os robôs: %g\n", calcular_distancia(robo1, robo2));

    return 0;
}
