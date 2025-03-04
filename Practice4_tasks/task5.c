#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[201]; 

    printf("Введите секретный отчёт: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    char *copy = strdup(input);
    if (copy == NULL) {
        fprintf(stderr, "Ошибка: не удалось выделить память.\n");
        return 1; 
    }

    printf("Оригинал: %s\n", input);
    printf("Копия: %s\n", copy);

    free(copy);

    return 0;
}
