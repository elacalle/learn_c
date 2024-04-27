#include<stdio.h>

void volume()
{
    double radio, volume;
    printf("Enter the radio information: \n");
    scanf("%lf", &radio);
    volume = (3.0 / 4.0) * 2.0 * radio * 3.1415;

    printf("The sphere volume is: %g cm3", volume);
}
