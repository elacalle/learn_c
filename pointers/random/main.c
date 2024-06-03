#include <stdio.h>;
#include <stdlib.h>;
#include <math.h>;

float randomNumber();

int main () {
    float *pointer, result; 
    char exitKey;
    
    pointer = malloc(sizeof(float));
    *pointer = 1.0;

    while (1) {
        result = randomNumber(&pointer);
        printf("%.2f \n", result);

        exitKey = getchar();

        if (exitKey != '\n') {
            while (getchar() != '\n');
        }
    }
}

float randomNumber(int *seed) {
    float multiplier = 5, add = 3, module = 16;

    float result = (multiplier * *seed) + add;
    result = fmod(result, module);
    *seed = result;

    return  result / 16;
} 