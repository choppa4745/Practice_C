#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void remove_spaces(char *str) {
    char *dst = str;
    while (*str) {
        if (*str != ' ') {
            *dst++ = *str;
        }
        str++;
    }
    *dst = '\0';
}

void replace_vowels(char *str) {
    while (*str) {
        if (strchr("aeiouyAEIOUY", *str)) {
            *str = '*';
        }
        str++;
    }
}

void invert_case(char *str) {
    while (*str) {
        if (islower(*str)) {
            *str = toupper(*str);
        } else if (isupper(*str)) {
            *str = tolower(*str);
        }
        str++;
    }
}

int main() {
    char *input = NULL;
    size_t len = 0;

    printf("Введите строку: ");
    getline(&input, &len, stdin);
    input[strcspn(input, "\n")] = 0;

    int choice;
    printf("Выберите функцию обработки:\n");
    printf("1. Удаление пробелов\n");
    printf("2. Замена всех гласных на '*'\n");
    printf("3. Инвертирование регистра символов\n");
    printf("Введите номер функции (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            remove_spaces(input);
            printf("Результат: %s\n", input);
            break;
        case 2:
            replace_vowels(input);
            printf("Результат: %s\n", input);
            break;
        case 3:
            invert_case(input);
            printf("Результат: %s\n", input);
            break;
        default:
            printf("Неверный выбор.\n");
            break;
    }

    free(input);
    return 0;
}
