#include<stdio.h>

void characters() {
    int car = 0;
    car = getchar();
    printf("\n");
    printf("Output:");
    putchar(car);

    scanf("%*d*%d", &car);
    car = getchar();
    printf("\n");
    printf("Output:");
    putchar(car);
}
