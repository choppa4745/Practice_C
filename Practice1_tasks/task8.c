#include <stdio.h>

int main() {
    int N;

    printf("Введите максимальный вес груза в кг: ");
    scanf("%d", &N);

    if (N % 4 == 0) {
        int weightPerSection = N / 4;
        printf("Груз можно равномерно распределить.\n");
        printf("В каждом отсеке будет %d кг.\n", weightPerSection);
    } else {
        printf("Груз нельзя равномерно распределить по 4 отсекам.\n");
    }

    return 0;
}