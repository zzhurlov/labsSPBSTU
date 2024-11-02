#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void setBlue() {
    printf("\033[0;34m"); 
}

void setGreen() {
    printf("\033[0;32m"); 
}

void setRed() {
    printf("\033[0;31m"); 
}

void resetColor() {
    printf("\033[0m");
}


int getIntInput(const char *prompt) {
    int value;
    char term;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d%c", &value, &term) != 2 || term != '\n') {
            setRed();
            printf("Ошибка: введите целое число.\n");
            resetColor();
            while (getchar() != '\n'); // очистка буфера
        } else if (value <= 0) { // Проверка на положительное значение
            setRed();
            printf("Ошибка: значение должно быть положительным.\n");
            resetColor();
        } else {
            break;
        }
    }
    return value;
}

int main() {
    int N;
    
    N = getIntInput("Введите размер матрицы N x N: ");

    int A[N][N];
    int B[N][N];

    srand(time(NULL));
    

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 20 ; // случайные числа от 0 до 20
        }
    }

    // выведем значения массива A
    setBlue();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    resetColor();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = rand() % 20 ; // случайные числа от 0 до 20
        }
    }

    printf("\n");

    // выведем значения массива B
    setGreen();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    resetColor();


    int X[N][2*N];

    int k = 0;
    int z = 0;
    int sm = 0;

    int flag = 0;
    // Формируем матрицу X
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2*N; j++) {

            if (sm == 2) {
                sm = 0;
                z += 1;
                }

            if (z >= N) {
                z = 0;
                k++;
            }

            if (flag == 0){
                X[i][j] = A[k][z];
                sm++;
                flag = 1;
            }
            else {
                X[i][j] = B[k][z];
                sm++;
                flag = 0;
            }
        }
    }

    // Выводим результирующую матрицу X
    printf("Результирующая матрица X:\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2*N; j++) {
            if (j % 2 == 0){
                setBlue();
                printf("%d ", X[i][j]);
                resetColor();
            }
            else {
                setGreen();
                printf("%d ", X[i][j]);
                resetColor();
            }
        }
        printf("\n");
    }
    
    return 0;
}