#include <stdio.h>

int main()
{
    int num_vogais = 0, num_consoantes = 0;
    char caractere;

    printf("Entre com uma frase: ");
    scanf("%c", &caractere);
    while (caractere != '\n') {
        if ('A' <= caractere && caractere <= 'Z') {
            caractere -= 'A' - 'a';
        }
        if (caractere == 'a' || caractere == 'e' ||
            caractere == 'i' || caractere == 'o' || caractere == 'u') {
            num_vogais++;
        } else if ('a' <= caractere && caractere <= 'z') {
            num_consoantes++;
        }
        scanf("%c", &caractere);
    }
    printf("Número de vogais: %d\n", num_vogais);
    printf("Número de consoantes: %d\n", num_consoantes);

    return 0;
}