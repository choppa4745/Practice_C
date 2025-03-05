#include <stdio.h>
#include <stdlib.h> 

typedef struct {
    char name[20];
    int age;
    float gpa;
} Student;

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    Student *students = (Student *)malloc(n * sizeof(Student));
   
    for (int i = 0; i < n; ++i) {
        printf("Enter name, age and GPA for student : ");
        scanf("%s %d %f", students[i].name, &students[i].age, &students[i].gpa);
    }

    for (int i = 0; i < n; ++i) {
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("GPA: %.2f\n", students[i].gpa);
    }

    free(students);
    return 0;
}