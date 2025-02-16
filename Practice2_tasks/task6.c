#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    Gasoline, 
    Diesel, 
    Electric
    } EngineType;

typedef struct {
    char brand[50];
    char model[50];
    int year;
    EngineType engine;
    } Vehicle;

int main() {
    int n;
    scanf("%d", &n);
    Vehicle *vehicles = (Vehicle *)malloc(n * sizeof(Vehicle));

    for (int i = 0; i < n; i++) {
        char engineTypeStr[20]; 
        printf("Enter brand, model, year and engine type (Gasoline, Diesel, Electric) for vehicle %d: ", i + 1);
        scanf("%s %s %d %s", vehicles[i].brand, vehicles[i].model, &vehicles[i].year, engineTypeStr);

        if (strcmp(engineTypeStr, "Gasoline") == 0) {
            vehicles[i].engine = Gasoline;
        } else if (strcmp(engineTypeStr, "Diesel") == 0) {
            vehicles[i].engine = Diesel;
        } else if (strcmp(engineTypeStr, "Electric") == 0) {
            vehicles[i].engine = Electric;
        } else {
            printf("Using Gasoline as default.\n");
            vehicles[i].engine = Gasoline;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("Vehicle: %s %s\nYear: %d\nEngine Type: %s\n\n", vehicles[i].brand, vehicles[i].model, vehicles[i].year, vehicles[i].engine == 0 ? "Gasoline" : vehicles[i].engine == 1 ? "Diesel" : "Electric");
    }

    return 0;
}