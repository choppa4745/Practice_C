#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *buffer = NULL;
size_t buffer_size = 0; 

void alloc_memory(size_t size) {
    if (buffer != NULL) {
        printf("Ошибка: память уже выделена. Сначала освободите её.\n");
        return;
    }
    buffer = malloc(size);
    if (buffer == NULL) {
        printf("Ошибка: не удалось выделить память.\n");
        return;
    }
    buffer_size = size;
    printf("Выделено %zu байт памяти.\n", size);
}

void free_memory() {
    if (buffer == NULL) {
        printf("Ошибка: память не выделена.\n");
        return;
    }
    free(buffer);
    buffer = NULL;
    buffer_size = 0;
    printf("Память освобождена.\n");
}

void write_memory(const char *text) {
    if (buffer == NULL) {
        printf("Ошибка: память не выделена.\n");
        return;
    }
    strncpy(buffer, text, buffer_size - 1);
    buffer[buffer_size - 1] = '\0'; 
    printf("Текст записан в память.\n");
}

void print_memory() {
    if (buffer == NULL) {
        printf("Ошибка: память не выделена.\n");
        return;
    }
    printf("Данные в памяти: %s\n", buffer);
}

int main() {
    char command[256];

    while (1) {
        printf("Введите команду: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; 

        if (strncmp(command, "alloc ", 6) == 0) {
            size_t size = atoi(command + 6);
            alloc_memory(size);
        } else if (strcmp(command, "free") == 0) {
            free_memory();
        } else if (strncmp(command, "write ", 6) == 0) {
            write_memory(command + 6);
        } else if (strcmp(command, "print") == 0) {
            print_memory();
        } else if (strcmp(command, "exit") == 0) {
            free_memory(); 
            printf("Выход из программы.\n");
            break;
        } else {
            printf("Неизвестная команда.\n");
        }
    }

    return 0;
}
