#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
    int numericGrade;
    char letterGrade[3];
} Grade;

int main() {
    int n;
    printf("Enter the number of grades: ");
    scanf("%d", &n);

    Grade *grades = (Grade *)malloc(n * sizeof(Grade));

    for (int i = 0; i < n; i++) {
        char input[10];
        printf("Enter grade %d (numeric or letter): ", i + 1);
        scanf("%s", input);

        if (sscanf(input, "%d", &grades[i].numericGrade) == 1) {
        } else {
            strncpy(grades[i].letterGrade, input, sizeof(grades[i].letterGrade) - 1);
            grades[i].letterGrade[sizeof(grades[i].letterGrade) - 1] = '\0';
        }
    }

    for (int i = 0; i < n; i++) {
        if (grades[i].numericGrade != 0) {
            printf("Grade: %d\n", grades[i].numericGrade);
        } else {
            printf("Grade: %s\n", grades[i].letterGrade);
        }
    }

    free(grades);
    return 0;
}