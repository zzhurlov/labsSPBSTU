#include <stdio.h>
#include <math.h>

// Функция для вычисления факториала в типе double
double factorial(int n) {
    double result = 1.0;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Нормализация x по модулю 2π
double normalize_angle(double x) {
    const double TWO_PI = 2.0 * M_PI;
    while (x > TWO_PI) {
        x -= TWO_PI;
    }
    while (x < -TWO_PI) {
        x += TWO_PI;
    }
    return x;
}

double calculate_cos_cubed(double x, double epsilon) {
    x = normalize_angle(x);  // Нормализуем x по модулю 2π
    double sum = 0.0;
    int n = 0;
    double term;
    double prer;
    double next_term;

    // Начальное значение первого члена
    term = pow(-1, n) * (pow(3, 2 * n) + 3) * pow(x, 2 * n) / factorial(2 * n) / 4;
    sum += term;

    // Начальное значение второго члена
    n++;
    prer = -1 * (pow(3, 2 * n) + 3) * factorial(2 * n - 2) * pow(x, 2) / factorial(2 * n) / (pow(3, 2 * n - 2) + 3);
    next_term = term * prer;
    sum += next_term;

    // Цикл для расчета следующих членов
    while (fabs(next_term - term) > epsilon) {
        n++;
        
        // Проверка на переполнение
        if (factorial(2 * n) == 0 || (pow(3, 2 * n - 2) + 3) == 0) {
            printf("Предупреждение: переполнение при n = %d\n", n);
            break;
        }
        
        prer = -1 * (pow(3, 2 * n) + 3) * factorial(2 * n - 2) * pow(x, 2) / factorial(2 * n) / (pow(3, 2 * n - 2) + 3);
        term = next_term;
        next_term = term * prer;
        sum += next_term;
    }

    return sum;
}

int main(void) {
    double x_start, x_end, dx, epsilon, x_ideal;

    printf("Введите x_start, x_end, dx, epsilon: ");
    scanf("%lf %lf %lf %lf", &x_start, &x_end, &dx, &epsilon);

    printf("\nТаблица 1 – Вывод данных для разных x\n");
    printf("x\tf_x\t\tF_x\t\tδ\n");

    for (double x = x_start; x <= x_end; x += dx) {
        double f_x = calculate_cos_cubed(x, epsilon);
        double F_x = pow(cos(x), 3);
        double delta = fabs(f_x - F_x);
        
        printf("%.2lf\t%lf\t%lf\t%lf\n", x, f_x, F_x, delta);
    }

    printf("Введите x_ideal: ");
    scanf("%lf", &x_ideal);
    printf("\nТаблица 2 – Вывод данных для разной точности для x_ideal\n");
    printf("ε\t\tf_x_ideal\tF_x_ideal\tδ\n");

    // Массив значений epsilon
    double eps_values[] = {0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001, 0.0000001};

    // Цикл для вывода таблицы 2
    for (int i = 0; i < 7; i++) {
        epsilon = eps_values[i];  // Устанавливаем текущее значение epsilon
        double f_x_ideal = calculate_cos_cubed(x_ideal, epsilon);  // Рядная функция
        double F_x_ideal = pow(cos(x_ideal), 3);  // Точное значение cos^3(x_ideal)
        double delta = sqrt(fabs(f_x_ideal * f_x_ideal - F_x_ideal * F_x_ideal));  // Невязка

        // Вывод строки таблицы 2
        printf("%.7f\t%f\t%f\t%f\n", epsilon, f_x_ideal, F_x_ideal, delta);
    }

    return 0;
}