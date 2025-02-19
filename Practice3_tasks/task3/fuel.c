#include <stdio.h>
#include "ship.h"

void check_fuel(int fuel_level) {
    if (fuel_level < 10) {
        printf("Внимание: уровень топлива ниже 10%%! Текущий уровень: %d%%\n", fuel_level);
    } else {
        printf("Уровень топлива в норме: %d%%\n", fuel_level);
    }
}