#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функція для ініціалізації масиву випадковими числами
void initializeArray(int *array, int n) {
    for (int i = 0; i < n; ++i) {
        array[i] = rand() % 201 - 100; // Генерація випадкового числа в діапазоні [-100; 100]
    }
}

// Функція для виведення масиву на екран
void printArray(int *array, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Функція для обчислення суми елементів з непарними номерами
int sumOddIndexElements(int *array, int n) {
    int sum = 0;
    for (int i = 1; i < n; i += 2) {
        sum += array[i];
    }
    return sum;
}

// Функція для обчислення суми елементів між першим і другим додатними елементами
int sumBetweenFirstTwoPositive(int *array, int n) {
    int firstPositiveIndex = -1;
    int secondPositiveIndex = -1;

    // Знайти індекси першого та другого додатних елементів
    for (int i = 0; i < n; ++i) {
        if (array[i] > 0) {
            if (firstPositiveIndex == -1) {
                firstPositiveIndex = i;
            } else {
                secondPositiveIndex = i;
                break;
            }
        }
    }

    // Якщо знайдено менше двох додатних елементів, повернути 0
    if (firstPositiveIndex == -1 || secondPositiveIndex == -1) {
        return 0;
    }

    int sum = 0;
    for (int i = firstPositiveIndex + 1; i < secondPositiveIndex; ++i) {
        sum += array[i];
    }
    return sum;
}

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    int continueProgram;

    do {
        int n;
        printf("Введіть кількість елементів масиву (n): ");
        while (scanf("%d", &n) != 1 || n <= 0) {
            printf("Некоректне введення. Введіть додатне ціле число: ");
            while (getchar() != '\n'); // Очищення буфера вводу
        }

        int array[n];

        initializeArray(array, n);
        printf("Згенерований масив:\n");
        printArray(array, n);

        int sumOdd = sumOddIndexElements(array, n);
        printf("Сума елементів з непарними номерами: %d\n", sumOdd);

        int sumBetweenPositives = sumBetweenFirstTwoPositive(array, n);
        printf("Сума елементів між першим і другим додатними елементами: %d\n", sumBetweenPositives);

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
