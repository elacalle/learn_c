#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void sort(char **list);
int gt(char *word, char *otherWord);

#define MAX_SIZE 255
int main() {
    char *list[] = { "hola", "mundo", "esto", "es", "c", NULL };

    sort(list);

    for(int i = 0; i < 5; i++) {
        printf("%s \n", list[i]);
    }
}

void sort(char **list) {
    int length = 5, swapped = 0;
    char *temp;

    do {
        swapped = 0;

        for(int i = 0; i + 1 < length; i++) { 
            if(gt(list[i], list[i + 1])) {
                temp = *(list + i);
                *(list + i) = *(list + i + 1);
                *(list + i + 1) = temp;
                
                swapped = 1;
            }
        }

        length--;
    }
    while (swapped);
}

int gt(char *word, char *otherWord) {
    if (word[strlen(word) - 1] < otherWord[strlen(otherWord) - 1]) {
        return 1;
    }

    return 0;
}