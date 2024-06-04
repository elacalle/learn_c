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
    struct point *currentObject;
    seed = malloc(sizeof(float));
    *seed = time(NULL);

    for (int i = 0; i < 1000; i++) {
        currentObject = malloc(sizeof(main));

        assignRandomNumber(currentObject);

        if(isValidObject(currentObject)) {
            validObjects += 1;
        }

        free(currentObject);
    }
 
    probability = validObjects / 1000.0;
    volume = probability * 8;

    printf("valid points %d \n", validObjects);
    printf("Probability %.2f \n", probability);
    printf("Sphere volume is %.2f \n", volume);

    return 0;
}

int isValidObject(struct point *currentObject) {
    float result; 
    result = pow(currentObject->x, 2) + pow(currentObject->y, 2) + pow(currentObject->z,  2);

    if(result < 1) {
        return 1;
    }

    return 0;
}

void assignRandomNumber(struct point *currentObject) {
    currentObject->x = randomNumber();
    currentObject->y = randomNumber();
    currentObject->z = randomNumber();
}

float randomNumber() {
    float multiplier = 5, add = 3, module = 16;

    float result = (multiplier * *seed) + add;
    result = fmod(result, module);
    *seed = result;

    return  result / 16;
} 