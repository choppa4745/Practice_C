#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

int compare_alphabetically(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int compare_by_length(const void *a, const void *b) {
    return strlen(*(const char **)a) - strlen(*(const char **)b);
}

int count_vowels(const char *str) {
    int count = 0;
    while (*str) {
        char ch = tolower(*str);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

int compare_by_vowel_count(const void *a, const void *b) {
    return count_vowels(*(const char **)a) - count_vowels(*(const char **)b);
}

int main() {
    char *strings[MAX_STRINGS];
    int n;

    printf("Введите количество строк (максимум %d): ", MAX_STRINGS);
    scanf("%d", &n);
    getchar(); 

    if (n > MAX_STRINGS) {
        printf("Ошибка: превышено максимальное количество строк.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        strings[i] = malloc(MAX_LENGTH * sizeof(char));
        printf("Введите строку %d: ", i + 1);
        fgets(strings[i], MAX_LENGTH, stdin);
        strings[i][strcspn(strings[i], "\n")] = 0; 
    }

    int choice;
    printf("Выберите режим сортировки:\n");
    printf("1. По алфавиту\n");
    printf("2. По длине строки\n");
    printf("3. По количеству гласных букв\n");
    printf("Введите номер функции (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            qsort(strings, n, sizeof(char *), compare_alphabetically);
            break;
        case 2:
            qsort(strings, n, sizeof(char *), compare_by_length);
            break;
        case 3:
            qsort(strings, n, sizeof(char *), compare_by_vowel_count);
            break;
        default:
            printf("Неверный выбор.\n");
            for (int i = 0; i < n; i++) {
                free(strings[i]);
            }
            return EXIT_FAILURE;
    }

    printf("Отсортированные строки:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]); 
    }

    return EXIT_SUCCESS;
}
