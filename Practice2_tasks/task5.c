#include <stdio.h>
#include <stdlib.h>

typedef union {
    int i;
    float f;
    char str[20];
} Data;

int main() {
    int choice;
    scanf("%d", &choice);
    Data data;

    switch (choice) {
        case 1:
            scanf("%d", &data.i);
            printf("Integer: %d\n", data.i);
            break;
        case 2:
            scanf("%f", &data.f);
            printf("Float: %.2f\n", data.f);
            break;
        case 3:
            scanf("%s", data.str);
            printf("String: %s\n", data.str);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}