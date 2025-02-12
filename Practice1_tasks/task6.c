#include <stdio.h>

int main() {
    int astronauts;

    printf("Введите количество космонавтов: ");
    scanf("%d", &astronauts);

    int modules2, modules3, modules4;
    int found = 0; 

    for (modules4 = 0; modules4 <= astronauts / 4; modules4++) {
        for (modules3 = 0; modules3 <= (astronauts - modules4 * 4) / 3; modules3++) {
            for (modules2 = 0; modules2 <= (astronauts - modules4 * 4 - modules3 * 3) / 2; modules2++) {
                if (modules4 * 4 + modules3 * 3 + modules2 * 2 == astronauts) {
                    printf("Можно разделить космонавтов на:\n");
                    printf("%d модулей по 4 человека\n", modules4);
                    printf("%d модулей по 3 человека\n", modules3);
                    printf("%d модулей по 2 человека\n", modules2);
                    found = 1; 
                }
            }
        }
    }

    if (!found) {
        printf("Невозможно разделить космонавтов на группы без остатка.\n");
    }

    return 0;
}