#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    Date date;
    char description[100];
} Event;

int main() {
    int n;
    scanf("%d", &n);
    Event events[n];

    for (int i = 0; i < n; i++) {
        printf("Enter name, date and description for event %d: ", i + 1);
        scanf("%s %d %d %d %s", events[i].name, &events[i].date.day, &events[i].date.month, &events[i].date.year, events[i].description);
    }

    for (int i = 0; i < n; i++) {
        printf("Event: %s\nDate: %d/%d/%d\nDescription: %s\n\n", events[i].name, events[i].date.day, events[i].date.month, events[i].date.year, events[i].description);
    }

    return 0;
}