#include<stdio.h>
#include<math.h>

float factorial(float);

void series() {
    float serie = 1.0;
    float accumulator = 1.0;
    float lastSerie = 1.0;
    float variable = 0.0;
    float errorGap = 0.0000001;

    printf("Enter your number: \n");
    scanf("%f", &variable);

    while(lastSerie >= errorGap) {
        lastSerie = pow(variable, serie) / factorial(serie);

        accumulator = accumulator + lastSerie;

        serie++;
    }

    printf("Summation of the series is: %2.7f", accumulator);
}

float factorial(float serie) {
  float accumulator = 1.0;

  for(float i = 1.0; i <= serie; i++) {
    accumulator = accumulator * i;
  }

  return accumulator;
}
