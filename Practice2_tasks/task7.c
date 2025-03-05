#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

int main() {
    int n;
    scanf("%d", &n);
    Student *students = (Student *)malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++) {
        scanf("%s %d %f", students[i].name, &students[i].age, &students[i].gpa);
    }

    for (int i = 0; i < n; i++) {
        printf("Name: %s\nAge: %d\nGPA: %.1f\n\n", students[i].name, students[i].age, students[i].gpa);
    }

    free(students);
    return 0;
}