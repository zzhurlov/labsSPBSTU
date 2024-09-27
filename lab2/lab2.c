#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ClearStdin()
{
    int rv = 1;
    int ch;
    while (1) {
        ch = getchar();
        if (ch == '\n' || ch == EOF) {
            break;
        }
        rv = 0;
    }
    return rv;
}

int main(void)
{
    srand(time(NULL));
    int a = rand()%101;
    int j = 1;
    for (int i = 1; i <= 10; i++)
    {
        int num;
        int readCount;
        int isEmpty;
        while (1) {
            printf("Введите число:\n");
            readCount = scanf("%d", &num);
            isEmpty = ClearStdin();
            if (readCount == 1 && isEmpty != 0) {
                break;
            }
            printf("Неверный формат числа\n");
        }

        if (0 > num || num > 100)
            printf("Вы должны угадать число от 0 до 100\n");

        else if (num == a)
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

        else if (num < a)
            printf("Вы ввели число меньшее загаданного\n");
        
        j = j + 1;
    }
}