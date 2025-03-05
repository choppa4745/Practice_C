#include <stdio.h>
#include <stdlib.h>

typedef float (*operation_func)(float, float);

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        printf("Ошибка: деление на ноль.\n");
        exit(EXIT_FAILURE);
    }
    return a / b;
}

operation_func get_operation(char op) {
    switch (op) {
        case '+': return add;
        case '-': return subtract;
        case '*': return multiply;
        case '/': return divide;
        default: return NULL;
    }
}

int main() {
    float num1, num2;
    char operator;

    printf("Введите выражение (например, '12 + 34'): ");
    if (scanf("%f %c %f", &num1, &operator, &num2) != 3) {
        printf("Ошибка: некорректный ввод.\n");
        return EXIT_FAILURE;
    }

    operation_func operation = get_operation(operator);
    if (operation == NULL) {
        printf("Ошибка: неподдерживаемая операция '%c'.\n", operator);
        return EXIT_FAILURE;
    }

    float result = operation(num1, num2);
    printf("Результат: %.2f\n", result);

    return EXIT_SUCCESS;
}

