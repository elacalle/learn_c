#include <stdio.h>
#include <time.h>

#define MAX 1.0
#define MIN 49.0
#define true 1
#define false 0 
#define LENGTH 6

double rnd(long *prandom);
void sort(int *list);
int exists(int *list, int expectedNumber);

int main () {
    int result, randomNumbers[LENGTH];
    long seed = time(NULL) % 65536;

    for(long i = 0.0; i < 6.0; i++) {
        do {
            result = (int)((MAX - MIN + 1) * rnd(&seed) + MIN);
        }
        while(exists(randomNumbers, result));

        randomNumbers[i] = result; 
    }

    sort(randomNumbers);

    for(int i = 0; i < 6; i++) {
        printf("%d \n", randomNumbers[i]);
    }
}

int exists(int *list, int expectedNumber) {
    for(int i = 0; i < LENGTH; i++) {
        if(list[i] == expectedNumber) {
            return true;
        }
    }

    return false;
}

double rnd(long *prandom) {
    *prandom = (25173 * *prandom + 13849) % 65536;

    return((double)*prandom / 65536);
}

void sort(int *list) { 
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j + 1 < (LENGTH - i); j++) {
            if(list[j] > list[j+1]) {
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}