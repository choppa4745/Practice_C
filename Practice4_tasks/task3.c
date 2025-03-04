#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    char input[200]; 
    const char delimiter[] = ";"; 

    printf("Введите имена космонавтов: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    char *input_copy = strndup(input, sizeof(input));

    char *token = strtok(input_copy, delimiter);
    
    while (token != NULL) {
        printf("%s\n", token); 
        token = strtok(NULL, delimiter); 
    }

    free(input_copy);

    return 0;
}
