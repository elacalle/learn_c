#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 255
int main() {
    char *row, buffer[MAX_SIZE];
    char **pointer = malloc(sizeof(char *));
    int wordLength, size = 0;

    while (size <= 2) {
        printf("Write a word:");
        scanf("%s", buffer);
        wordLength = strlen(buffer);

        row = malloc(wordLength * sizeof(char*));
        strcpy(row, buffer);
        *(pointer + size) = row;

        size++;
        pointer = (char **) realloc(pointer, (size + 1) * sizeof(char *));
    }

    return 0;
}
