#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int grado;
  float *coef;
} tpolinomio;

int readPolinom();

int main() {
  readPolinom();
}

int readPolinom() {
  int result = 1, input, *pintArr, *temp, size = 0;
  pintArr = malloc(1 * sizeof(int));

  printf("Write any number, type any word to exit:\n");

  while (result != 0) {
    result = scanf("%d", &input);

    if(result) {
      int *temp = realloc(pintArr, (size + 1) * sizeof(int));

      if(temp == NULL) {
        printf("Error reallocating memory!\n");
        free(pintArr);
        return 1;
      }

      pintArr = temp;
      *(pintArr + size) = input;
      size++;
    }
  }
}


