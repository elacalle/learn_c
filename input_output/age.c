#include<stdio.h>

void age() {
    int originDate, targetDate;
    char nombre[100];

    printf("Introduce tu nombre: \n");
    scanf("%s", nombre);

    printf("Introduce tu ano de nacimiento: \n");
    scanf("%d", &originDate);

    printf("Introduce el ano actual: \n");
    scanf("%d", &targetDate);

    printf("Tu nombre es %s, tienes en %d", nombre, targetDate - originDate);
}
