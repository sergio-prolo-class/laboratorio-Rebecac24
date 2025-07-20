#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool eh_bissexto(int ano);
int num_dias(int mes, int ano);
bool eh_data_valida(int dia, int mes, int ano);
int dias_decorridos(int dia, int mes, int ano);

int main()
{
    int dia, mes, ano;
    printf("Entre com a data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dia, &mes, &ano);
    if (!eh_data_valida(dia, mes, ano)) {
        printf("Data inválida!\n");
        return EXIT_FAILURE;
    }
    printf("Dias decorridos: %d\n", dias_decorridos(dia, mes, ano));
    return EXIT_SUCCESS;
}

bool eh_bissexto(int ano)
{
    return (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0);
}

int num_dias(int mes, int ano)
{
    switch (mes) {
        case 2:
            return eh_bissexto(ano) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

bool eh_data_valida(int dia, int mes, int ano)
{
    if (mes < 1 || mes > 12) {
        return false;
    }
    return 1 <= dia && dia <= num_dias(mes, ano);
}

int dias_decorridos(int dia, int mes, int ano)
{
    int num = dia;
    switch (mes) {
        case 12: num += num_dias(11, ano);  // fallthrough
        case 11: num += num_dias(10, ano);  // fallthrough
        case 10: num += num_dias(9, ano);   // fallthrough
        case 9: num += num_dias(8, ano);    // fallthrough
        case 8: num += num_dias(7, ano);    // fallthrough
        case 7: num += num_dias(6, ano);    // fallthrough
        case 6: num += num_dias(5, ano);    // fallthrough
        case 5: num += num_dias(4, ano);    // fallthrough
        case 4: num += num_dias(3, ano);    // fallthrough
        case 3: num += num_dias(2, ano);    // fallthrough
        case 2: num += num_dias(1, ano);    // fallthrough
    }
    return num;
}
