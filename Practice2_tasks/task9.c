#include <stdio.h>
#include <string.h>

typedef enum {
    Sunny, 
    Cloudy, 
    Rainy
} Condition;

typedef struct {
    float temperature;
    float humidity;
    Condition condition;
} Weather;

int main() {
    Weather weather;
    char conditionStr[10];

    scanf("%f %f %s", &weather.temperature, &weather.humidity, conditionStr);

    if (strcmp(conditionStr, "Sunny") == 0) {
        weather.condition = Sunny;
    } else if (strcmp(conditionStr, "Cloudy") == 0) {
        weather.condition = Cloudy;
    } else if (strcmp(conditionStr, "Rainy") == 0) {
        weather.condition = Rainy;
    } else {
        printf("Invalid condition! Using Sunny as default.\n");
        weather.condition = Sunny;
    }

    printf("Temperature: %.1f°C\n", weather.temperature);
    printf("Humidity: %.1f%%\n", weather.humidity);
    printf("Condition: %s\n", 
           weather.condition == Sunny ? "Sunny" : 
           weather.condition == Cloudy ? "Cloudy" : "Rainy");

    return 0;
}