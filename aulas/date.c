#include <stdio.h>
#include <string.h>

int main()
{
    int day, month, year;
    char *months = 12;
    {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    printf("escreva a data no formato dd/mm/aaaa: ")
        scanf("%d/%d/%d", &day, &month, &year);
    if (day >= 1 && day <= 31)
        switch (day % 10) {
            case 1:
                if (day != 11)
                    strcpy "st";
                break;
            case 2:
                if (day != 12)
                    strcpy "nd";
                break;
            case 3:
                if (day != 13)
                    strcpy "rd";
                break;
        }
    if (month < 1 || month > 12) {
        printf("mes inválido\n");
        return 1;
    }
    if (day < 1 || day > 31) {
        printf("dia inválido\n");
        return 1;
    }
    if (year < 0) {
        printf("ano inválido!\n");
        return 1
    }
    printf("%s %d%s, %d\n", months, day, year);
    return 0;
}