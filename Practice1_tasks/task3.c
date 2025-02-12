#include <stdio.h>

int main() {
    char symbol;

    printf("Введите символ от 'A' до 'Z': ");
    scanf("%c", &symbol);

    if (symbol >= 'A' && symbol <= 'Z') {
        printf("Символ '%c' входит в допустимый диапазон.\n", symbol);
    } else {
        printf("Символ '%c' не входит в допустимый диапазон.\n", symbol);
    }

    return 0;
}
