#include<stdio.h>
#include<math.h>

void polynomial()
{
    float xValue;
    float result;

    printf("Enter value for X:");
    scanf("%f", &xValue);

    result = (3.0 * pow(xValue, 5)) - (5.0 * pow(xValue, 3.0)) + (2 * xValue) - 7;

    printf("Para x = %.2f, 3x^5 - 5x^3 + 2x - 7 = %.2f", xValue, result);
}

void polynomialVariable() {
    float xValue, a, b, c;
    float result;

    printf("Enter value for X:");
    scanf("%f", &xValue);

    printf("Enter value for a:");
    scanf("%f", &a);

    printf("Enter value for b:");
    scanf("%f", &b);

    printf("Enter value for c:");
    scanf("%f", &c);

    result = (a * pow(xValue, 5)) - (b * pow(xValue, 3.0)) + (c * xValue) - 7;

    printf("Para x = %.2f, 3a^5 - 5b^3 + 2c - 7 = %.2f", xValue, result);
}
