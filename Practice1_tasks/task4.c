#include <stdio.h>

int main() {
    int current_date = 20250211;
    int date;

    printf("Введите дату миссии: ");
    scanf("%d", &date);

    if (date > current_date) {
        printf("Миссия запланированная на '%d' - это миссия будущего.\n", date);
    } else {
        printf("Миссия запланированная на '%d' - это не миссия будущего.\n", date);
    }

    return 0;
}
