#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int main (){
    char str[100];
    printf("Enter your string: ");
    fgets(str, sizeof(str), stdin);

    size_t start = strspn(str, "#*");
    size_t len = strcspn(str + start, "#*");

    char *messege = strndup(str + start, len);

    printf("Очищенное сообщение: %s\n", messege);
    printf("Длина сообщения: %zu\n", len);

    free(messege);
    return 0;
}