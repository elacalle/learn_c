#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void sort(char ***list, int *size);
int gt(char *word, char *otherWord);
int input(char ***list, int *size);
void cleanKeyboardInput();

#define MAX_SIZE 255
int main() {
    int size = 0; 
    char **list = malloc(sizeof(char *));

    input(&list,  &size);
    sort(&list, &size);

    for(int i = 0; i < size; i++) {
        printf("%s\n", list[i]);
    }

    free(list);
}

int input(char ***list, int *size) {
    int result = 1;
    char word[MAX_SIZE], *newWord;
    char **tempDir;
    
    printf("Write a word: \n");

    while (1)
    {
        scanf("%s", word);

        if (strcmp(word, "exit") == 0) {
            break;
        }

        newWord = malloc(strlen(word) * sizeof(char));
        strcpy(newWord, word);
        (*list)[*size] = newWord;

        *size = *size + 1;
        tempDir = realloc(*list, (*size + 1) * sizeof(char *));

        *list = tempDir; 
        
        cleanKeyboardInput();
    }
}

void sort(char ***list, int *size) {
    int length = *size;
    int swapped;
    char *temp;

    do {
        swapped = 0;

        for (int i = 0; i + 1 < length; i++) {

            if (gt((*list)[i], (*list)[i + 1])) {
                temp = (*list)[i];
                (*list)[i] = (*list)[i + 1];
                (*list)[i + 1] = temp;

                swapped = 1;
            }
        }

        length--;
    } while (swapped);
}

int gt(char *word, char *otherWord) {
    if (word[strlen(word) - 1] > otherWord[strlen(otherWord) - 1]) {
        return 1;
    }

    return 0;
}

void cleanKeyboardInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}