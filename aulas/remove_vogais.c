#include <stdio.h>
#include <stdbool.h>

bool eh_vogal(char letra)
{
    char vogais[] = "aeiouAEIOU";
    for (int i = 0; i < 10; i++) {
        if (letra == vogais[i]) {
            return true;
        }
    }
    return false;
}

void remove_vogais(char palavra[])
{
    int j = 0;
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (!eh_vogal(palavra[i])) {
            palavra[i] = palavra[i];
            j++;
        }
    }
    palavra[j] = '\0';
}

int main()
{
    char palavra[11];
    printf("Entre com uma palavra: ");
    scanf("%10s", palavra);
    remove_vogais(palavra);
    printf("Palavra sem vogais: %s\n", palavra);
    return 0;
}