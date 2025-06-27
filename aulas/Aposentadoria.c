#include <stdio.h>

int main()
{
    // Variáveis
    int idade, tempo;
    printf("Entre com a idade: ");
    scanf("%d", &idade);
    printf("Entre com o tempo de serviço:");
    scanf("%d", &tempo);
    if (idade >= 65 || tempo >= 30 || (idade >= 60 && tempo >= 25)) {
        printf("Pode aposentar");
    } else {
        printf("Não pode se aposentar");
    }
    return 0;
}
