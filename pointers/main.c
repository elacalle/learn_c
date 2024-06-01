#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int degree;
  int *coef;
} tpolynomial;

tpolynomial* create();

int readPolynomial(tpolynomial *polynomial);
void inspectPolynomial(tpolynomial *polynomial);
void cleanKeyboardInput();

tpolynomial* add(tpolynomial *firstOperand, tpolynomial *secondOperand);

tpolynomial* min(tpolynomial *firstPolynomial, tpolynomial *secondPolynomial) ;
tpolynomial* max(tpolynomial *firstPolynomial, tpolynomial *secondPolynomial) ;
void refill(tpolynomial *minPolynomial, tpolynomial *maxPolynomial);

int main() {
  tpolynomial *firstPolynomial, *secondPolynomial;

  firstPolynomial = create();
  secondPolynomial = create();

  inspectPolynomial(firstPolynomial);
  inspectPolynomial(secondPolynomial);
  add(firstPolynomial, secondPolynomial);

  free(firstPolynomial);
  free(secondPolynomial);

  return 0;
}

tpolynomial* create() {
  tpolynomial *newPolynomial;
  newPolynomial = malloc(sizeof(tpolynomial));

  readPolynomial(newPolynomial);

  return newPolynomial;
}

tpolynomial* add(tpolynomial *firstOperand, tpolynomial *secondOperand) {
  tpolynomial *minPolynomial, *maxPolynomial;
  tpolynomial *newPolynomial = malloc(sizeof(tpolynomial));

  maxPolynomial = max(firstOperand, secondOperand);
  minPolynomial = min(firstOperand, secondOperand);

  refill(minPolynomial, maxPolynomial);
}

void refill(tpolynomial *minPolynomial, tpolynomial *maxPolynomial) {
  int *oldCoeficient = minPolynomial->coef, *newCoefficient;
  newCoefficient = malloc(maxPolynomial->degree * sizeof(int));

  for(int i = maxPolynomial->degree; i >= 1; i--) {
    int index = maxPolynomial->degree - i;
    int lowerIndex = minPolynomial->degree - i;

    if(lowerIndex < 0) {
      *(newCoefficient + index) = 0;
    } else {
      *(newCoefficient + index) = *(oldCoeficient + lowerIndex);
    }
  }

  minPolynomial->coef = newCoefficient;
  free(oldCoeficient);
}

tpolynomial* max(tpolynomial *firstPolynomial, tpolynomial *secondPolynomial) {
  if (firstPolynomial->degree > secondPolynomial->degree) { return firstPolynomial; }

  return secondPolynomial;
}

tpolynomial* min(tpolynomial *firstPolynomial, tpolynomial *secondPolynomial) {
  if (firstPolynomial->degree < secondPolynomial->degree) { return firstPolynomial; }

  return secondPolynomial;
}

void inspectPolynomial(tpolynomial *polynomial) {
  if(!polynomial->degree) {
    printf("Polynomial is empty \n");  
  }

  printf("Polynomial degree is: %d \n", polynomial->degree);
  printf("Polynomial coefficients are: \n");

  for(int i = 0; i < polynomial->degree; i++) {
    printf("%d^%d: \n", *(polynomial->coef + i), polynomial->degree - i);
  }
}

int readPolynomial(tpolynomial *polynomial) {
  int result = 1, input, *temp, size = 0;
  polynomial->coef = (int *)malloc(1 * sizeof(int));

  printf("Write any number, type any word to exit:\n");

  while (result != 0) {
    result = scanf("%d", &input);

    if(result) {
      int *temp = realloc(polynomial->coef, (size + 1) * sizeof(int));

      if(temp == NULL) {
        printf("Error reallocating memory!\n");
        free(polynomial->coef);
        return 1;
      }

      polynomial->coef = temp;
      *(polynomial->coef + size) = input;
      size++;
    }
  }

  cleanKeyboardInput();

  polynomial->degree = size;
}

void cleanKeyboardInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


