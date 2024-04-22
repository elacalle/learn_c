#include<stdio.h>
#include<math.h>

void quadratic() {
    float a, b, c, result, powerOfB;
    int operation = 4;

    printf("Enter A number: ");
    scanf("%f", &a);

    printf("Enter B number: ");
    scanf("%f", &b);

    printf("Enter C number: ");
    scanf("%f", &c);

    operation = operation * a * c;

    if (operation > 0) {
        powerOfB = pow(b, 2) - operation;
    } else {
        powerOfB = pow(b, 2) + (operation * -1);
    }

    result = ((-1 * b) + sqrt(powerOfB)) / (2 * a);
    printf("Result is: %.2f", result);
}
