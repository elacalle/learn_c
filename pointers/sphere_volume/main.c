#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

float randomNumber();

struct point
{
    float x;
    float y;
    float z;
};

void assignRandomNumber(struct point *currentObject);
int isValidObject(struct point *currentObject);

float *seed; 

int main() {
    float result, probability, volume;
    int validObjects = 0;
    struct point *randomPoint;
    seed = malloc(sizeof(float));
    *seed = time(NULL);

    for (int i = 0; i < 1000; i++) {
        randomPoint = malloc(sizeof(main));

        assignRandomNumber(randomPoint);

        if(isValidObject(randomPoint)) {
            validObjects += 1;
        }

        free(randomPoint);
    }
 
    probability = validObjects / 1000.0;
    volume = probability * 8;

    printf("valid points %d \n", validObjects);
    printf("Probability %.2f \n", probability);
    printf("Sphere volume is %.2f \n", volume);

    return 0;
}

int isValidObject(struct point *randomPoint) {
    float result; 
    result = pow(randomPoint->x, 2) + pow(randomPoint->y, 2) + pow(randomPoint->z,  2);

    if(result < 1) {
        return 1;
    }

    return 0;
}

void assignRandomNumber(struct point *randomPoint) {
    randomPoint->x = randomNumber();
    randomPoint->y = randomNumber();
    randomPoint->z = randomNumber();
}

float randomNumber() {
    float multiplier = 5, add = 3, module = 16;

    float result = (multiplier * *seed) + add;
    result = fmod(result, module);
    *seed = result;

    return  result / 16;
} 