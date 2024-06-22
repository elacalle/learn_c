#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort(char *dictionary[], int size);
void merge(char *dictionaryOne[], int sizeOne, char *dictionaryTwo[], int sizeTwo, char ***result, int sizeResult);
int compare(char *first, char *second);
void printf_array(char *dictionaryOne[], int size);

int main() {
    int sizeOne, sizeTwo, sizeResult;
    char *dictionaryOne[] = { "casa", "xilofono", "pera", "asno" };
    char *dictionaryTwo[] = { "manzana",  "cebolla", "pepino", "cheesecake", "multiverso", "fresno", "pixar" };
    char **output;

    sizeOne = sizeof(dictionaryOne) / sizeof(char *);
    sort(dictionaryOne, sizeOne);

    sizeTwo = sizeof(dictionaryTwo) / sizeof(char *);
    sort(dictionaryTwo, sizeTwo);

    sizeResult = sizeOne + sizeTwo;

    merge(dictionaryOne, sizeOne, dictionaryTwo, sizeTwo, &output, sizeResult);

    printf_array(output, sizeResult);

    free(output);

    return 1;
}

void printf_array(char *list[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", list[i]);
    }
}

void merge(char *dictionaryOne[], int sizeOne, char *dictionaryTwo[], int sizeTwo, char ***result, int sizeResult) {
    char **remaningList;
    int indexA = 0, indexB = 0, index, completedIndex;

    *result = malloc(sizeof(char *) * sizeResult);

    while((indexA <= sizeOne - 1) && (indexB <= sizeTwo - 1)) {
        if(compare(dictionaryOne[indexA], dictionaryTwo[indexB])) {
            (*result)[index] = dictionaryTwo[indexB];

            indexB++;
        } else {
            (*result)[index] = dictionaryOne[indexA];

            indexA++;
        }

        index++;
    }

    if(indexA <= sizeOne - 1) {
        completedIndex = indexB;
        remaningList = dictionaryOne;
    } else {
        completedIndex = indexA;
        remaningList = dictionaryTwo;
    }

    for (int i = 0; index + i < sizeResult; i++) {
        (*result)[index] = remaningList[index - completedIndex];

        index += i;
    }
}

void sort(char *dictionary[], int size) {
    char *temp;
    int sorted = 0;

    do {
        sorted = 0;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (compare(dictionary[j], dictionary[j + 1])) {
                    temp = dictionary[j + 1];
                    dictionary[j + 1] = dictionary[j];
                    dictionary[j] = temp;

                    sorted = 1;
                }
            }
        }
    } while (sorted);
}

int compare(char *first, char *second) {
    int charOne = strlen(first), charTwo = strlen(second), min, result = 0;
    min = charOne < charTwo ? charOne : charTwo;


    for(int i = 0; i < min; i++) {
        if(first[i] == second[i]) {
            continue;
        }

        result = second[i] < first[i] ? 1 : 0;
        break;
    }

    return result;
}