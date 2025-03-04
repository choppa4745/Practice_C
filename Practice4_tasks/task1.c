#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char ships[100][50];
    int n;

    printf("Введите количество кораблей (максимум %d): ", 100);
    scanf("%d", &n);

    printf("Введите названия кораблей:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", ships[i]);
    }

    for (int i = 0; i < n; i++) {
        if (strncmp(ships[i], "SS", 2) == 0 || 
            (tolower(ships[i][0]) == 's' && tolower(ships[i][1]) == 's')) {
            printf("Первый корабль: %s\n", ships[i]);
            return 0; 
        }
    }

    printf("Не найдено\n");
    return 0;
}
