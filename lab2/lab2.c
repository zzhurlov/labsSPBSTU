#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int a = rand()%101;
    int j = 1;
    for (int i = 1; i <= 10; i++)
    {
        int num;
        printf("Введите число:\n");
        scanf("%d", &num);
        if (num == a)
        {
            printf("Вы угадали!\n");
            break;
        }
        else if (i == 10)
        {
            printf("Вы проиграли, загаданное число: %d\n", a);
            break;
        }
        else if (num > a)
            printf("Вы ввели число большее загаданного\n");

        else
            printf("Вы ввели число меньшее загаданного\n");
        j = j + 1;
    }
}