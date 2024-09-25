#include <stdio.h>
#include <math.h>

double F(double x, double a)
{
    return 1/(x/8 + 2*pow(cos(x), a));
}

int main(void)
{
    double x;
    printf("Введите значение переменной x начальное\n");
    scanf("%lf", &x);
    double x_end;
    printf("Введите значение переменной x конечное\n");
    scanf("%lf", &x_end);
    double delta_x;
    printf("Введите значение переменной дельта x\n");
    scanf("%lf", &delta_x);
    double a;
    printf("Введите значение переменной a\n");
    scanf("%lf", &a);

    printf("№п.п\t  x\t\t  a\t\t\t\t  y\n");
    int count = 1;
    while (x <= x_end)
    {
        double y = F(x, a);
        if ((x/8 + 2*pow(cos(x), a)) == 0)
            printf("%d\t%6.2lf\t%17.6lf\t\tDivision by zero\n", count++, x, a);
        else if ((a < 1) && (a > -1) && (a != 0) && (cos(x) < 0))
            printf("%d\t%6.2lf\t%17.6lf\t\tNegative number under the root\n", count++, x, a);
        else
            printf("%d\t%6.2lf\t%17.6lf\t\t%13.6lf\n", count++, x, a, y);
        x += delta_x;
    }
    return 0;
}