#include<stdio.h>
void charToInt() {
    char car1 = 'A', car2 = 65, car3 = 0;
    car3 = car1 + 'a' - 'A';
    printf("%d %c\n", car3, car3); // 96 a
    car3 = car2 + 32;
    printf("%d %c\n", car3, car3); // 97 a
}
