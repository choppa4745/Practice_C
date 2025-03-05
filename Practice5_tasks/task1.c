#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT 100

typedef struct {
    char *name;
    void (*func)(char *);
} Command;

void to_upper(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
    printf("Результат: %s\n", str);
}

void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
    printf("Результат: %s\n", str);
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    printf("Результат: %s\n", str);
}

void exit_program(char *str) {
    printf("Завершение программы.\n");
    exit(0);
}

int main() {
    Command commands[] = {
        {"upper", to_upper},
        {"lower", to_lower},
        {"reverse", reverse_string},
        {"exit", exit_program}
    };

    char input[MAX_INPUT];

    while (1) {
        printf("Введите команду (upper, lower, reverse, exit): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            exit_program(NULL);
        }

        int found = 0;
        for (int i = 0; i < sizeof(commands) / sizeof(Command); i++) {
            if (strcmp(input, commands[i].name) == 0) {
                printf("Введите строку: ");
                char str[MAX_INPUT];
                scanf(" %[^\n]", str);
                commands[i].func(str);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Неизвестная команда. Пожалуйста, попробуйте снова.\n");
        }
    }

    return 0;
}
