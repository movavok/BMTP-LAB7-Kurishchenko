#include <stdio.h>
#include <locale.h>

#define SIZE 19

int is_triangular(int index) {
    int sum = 0, n = 1;
    while (sum < index) {
        sum += n;
        if (sum == index) return 1;
        n++;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "ukr");

    int array[SIZE];
    int max_value;

    printf("Програма для обробки масиву: знаходження максимального елемента та його використання для заміни трикутних індексів.\n");
    printf("Розробник: Куріщенко Павло\n");
    printf("Версія: 1.0\n");
    printf("Мова інтерфейсу: українська\n\n");

    printf("Введіть %d елементів масиву:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Помилка: введено некоректне значення! Завершення програми.\n");
            return 1;
        }
    }

    max_value = array[0];
    for (int i = 1; i < SIZE; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (is_triangular(i + 1)) {
            array[i] = max_value;
        }
    }

    printf("Оновлений масив:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
