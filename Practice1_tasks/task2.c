#include <stdio.h>

int main(){
    int way;

    puts("Введите путь до заправки в м:");
    scanf("%d", &way);

    if (way > 500){
        printf("Distance of way is %d km! You can't get the goal.\n", way);
    } else{
        printf("Distance of way is %d km! You can get the goal.\n", way);
    }

    return 0;
}
