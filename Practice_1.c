#include <stdio.h>

int main(){
    int age;
    char name[50];

    fgets(name, sizeof(name), stdin);
    scanf("%s %d", name, &age);
    printf("Hello, %s! You are %d years old.\n", name, age);

    return 0;
}

