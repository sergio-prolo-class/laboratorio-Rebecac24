#include <stdio.h>

int main()
{
    char caractere;
    int vogais = 0, consoantes = 0;

    printf("Entre com uma frase: ");

    caractere = getchar();

    while (caractere != '\n') {
        if ((caractere >= 'A' && caractere <= 'Z') || (caractere >= 'a' && caractere <= 'z')
            if (caractere >= 'A' && caractere <= 'Z') {
            caractere = caractere + 32;
            if (caractere == 'a' || caractere == 'e' || caractere == 'i' ||
                caractere == 'o' || caractere == 'u') {
                vogais++;
            } else {
                consoantes++
            }

            caractere = getchar();
    }
    return 0;
    }