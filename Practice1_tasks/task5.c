#include <stdio.h>

int main() {
    double calculatedSpeed;
    double actualSpeed;

    printf("Введите расчетную скорость в м/с: ");
    scanf("%lf", &calculatedSpeed);

    printf("Введите фактическую скорость в м/с: ");
    scanf("%lf", &actualSpeed);

    double difference = actualSpeed - calculatedSpeed;


    if (difference > 0.1) {
        printf("Орбита нестабильна.\n");
    } else {
        printf("Орбита стабильна.\n");
    }

    return 0;
}