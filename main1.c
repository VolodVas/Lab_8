#include <stdio.h>

// Функція для збільшення кожного елемента матриці на 2
void incrementMatrixElements(int *matrix, int n, int m) {
    for (int i = 0; i < n * m; ++i) {
        *(matrix + i) += 2;
    }
}

// Функція для виведення матриці на екран
void printMatrix(int *matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", *(matrix + i * m + j));
        }
        printf("\n");
    }
}

int main() {
    int continueProgram;

    do {
        int n, m;

        // Введення розмірності матриці
        printf("Введіть кількість рядків (n): ");
        while (scanf("%d", &n) != 1 || n <= 0) {
            printf("Некоректне введення. Введіть додатне ціле число: ");
            while (getchar() != '\n'); // Очищення буфера вводу
        }

        printf("Введіть кількість стовпців (m): ");
        while (scanf("%d", &m) != 1 || m <= 0) {
            printf("Некоректне введення. Введіть додатне ціле число: ");
            while (getchar() != '\n'); // Очищення буфера вводу
        }

        int matrix[n][m];

        // Введення елементів матриці
        printf("Введіть елементи матриці:\n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("Елемент [%d][%d]: ", i, j);
                while (scanf("%d", &matrix[i][j]) != 1) {
                    printf("Некоректне введення. Введіть ціле число для елемента [%d][%d]: ", i, j);
                    while (getchar() != '\n'); // Очищення буфера вводу
                }
            }
        }

        // Виведення початкової матриці
        printf("Початкова матриця:\n");
        printMatrix((int *)matrix, n, m);

        // Збільшення кожного елемента матриці на 2
        incrementMatrixElements((int *)matrix, n, m);

        // Виведення зміненої матриці
        printf("Матриця після збільшення кожного елемента на 2:\n");
        printMatrix((int *)matrix, n, m);

        // Меню для продовження або завершення програми
        printf("Продовжити? (Так, введіть 1) (Ні, введіть 0): ");
        while (scanf("%d", &continueProgram) != 1 || (continueProgram != 0 && continueProgram != 1)) {
            printf("Некоректне введення. Введіть 1 для продовження або 0 для завершення: ");
            while (getchar() != '\n'); // Очищення буфера вводу
        }

    } while (continueProgram == 1);

    printf("Програму завершено.\n");

    return 0;
}
