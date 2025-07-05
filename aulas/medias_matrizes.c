#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int matriz[MAX][MAX], linhas, colunas;
    float soma = 0.0;

    printf("Entre com o número de linhas e colunas: ");
    scanf("%d %d", &linhas, &colunas);

    printf("Entre com os elementos da matriz: ");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMedias das linhas: ");
    for (int i = 0; i < linhas; i++) {
        soma = 0.0;
        for (int j = 0; j < colunas; j++) {
            soma += matriz[i][j];
        }
        printf("%g", soma / colunas);
    }

    printf("\n Media das colunas: ");
    for (int j = 0; j < colunas; j++) {
        soma = 0.0;
        for (int i = 0; i < linhas; i++) {
            soma += matriz[i][j];
        }
        printf("%g", soma / linhas);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
