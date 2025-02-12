#include <stdio.h>

int main(){
    int weight;

    puts("Введите ваш весв кг:");
    scanf("%d", &weight);

    if (weight < 60 || weight > 90){
        printf("Your weight is %d kg! You can't join the board.\n", weight);
    } else{
        printf("Your weight is %d kg! You can join the board.\n", weight);
    }

    return 0;
}
