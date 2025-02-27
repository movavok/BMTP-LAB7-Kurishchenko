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

    printf("�������� ��� ������� ������: ����������� ������������� �������� �� ���� ������������ ��� ����� ��������� �������.\n");
    printf("���������: �������� �����\n");
    printf("�����: 1.0\n");
    printf("���� ����������: ���������\n\n");

    printf("������ %d �������� ������:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("�������: ������� ���������� ��������! ���������� ��������.\n");
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

    printf("��������� �����:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
