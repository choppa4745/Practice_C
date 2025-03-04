#include <stdio.h>
#include <string.h>

int main() {
    char input[256];
    const char correct_code[] = "LAUNCH-2025";

    printf("Введите код запуска: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    if (strcasecmp(input, correct_code) == 0) {
        printf("Код принят\n");
    } else {
        printf("Ошибка: неверный код!\n");
    }

    return 0;
}
