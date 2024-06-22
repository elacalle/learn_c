#include<stdio.h>

int factorial(int n);

int main() {
    printf("%d\n", factorial(5)) ;
}

int factorial(int n) {
    if (n > 1) {
        return factorial(n-1) * n;
    } else {
        return n * 1;
    }
}