#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define true 1

typedef struct {
    char id[10];
    char lastName[30];
    char firstName[20];
    char address[30];
} trecord;

void menu();
void clear_stdin(void);
void write(trecord **records);
void printRecord(trecord *record);

trecord* searchById(trecord *trecord);
trecord* searchBySurname(trecord *trecord);

char* prompt(const char *message);
typedef trecord* (*FuncPtr)();

int main() {
    int option = 0;
    trecord *records[SIZE];
    FuncPtr pfn[2] = { searchById, searchBySurname };

    while(true) {
        system("clear");
        menu();
        scanf("%d", &option);

        clear_stdin();

        if(option < 1 || option > 4) {
            system("clear");
            free(prompt("Invalid option, press any key to continue. \n"));
        } else {
            if(option == 4) {
                break;
            } else if(option == 1) {
                write(records);
            } else {
                system("clear");
                trecord *output = (pfn[option - 1])(records);

                printRecord(output);

                free(prompt("Press any key to continue. \n"));
            }
        }
    }

    return 1;   
}

void clear_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // do nothing, just read and discard
    }
}

void menu() {
    printf("1. Write a record\n");
    printf("2. Search a record by ID\n");
    printf("3. Search a record by surname\n");
    printf("4. Exit\n");
}

void write(trecord **records) {
    system("clear");

    int i = 0;

    while(i < SIZE) {
        trecord *newRecord = malloc(sizeof(trecord));

        strcpy(newRecord->firstName, prompt("Write first name\n"));
        strcpy(newRecord->lastName, prompt("Write last name\n"));
        strcpy(newRecord->id, prompt("Write an ID\n"));
        strcpy(newRecord->address, prompt("Write an address\n"));

        records[i] = newRecord;

        if(prompt("Continue? y/n \n")[0] == 'n') {
            break;
        }
    }
}


char* prompt(const char *message) {

    clear_stdin();
    // Mostrar el mensaje al usuario
    printf("%s", message);
    
    // Asignar memoria para el buffer
    char *buffer = malloc(100);
    if (buffer == NULL) {
        fprintf(stderr, "Error al asignar memoria\n");
        exit(EXIT_FAILURE);
    }
    
    // Leer la entrada del usuario
    if (fgets(buffer, 100, stdin) == NULL) {
        fprintf(stderr, "Error al leer la entrada\n");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    clear_stdin();

    return buffer;
}

trecord* searchById(trecord *records) {
     char *key = prompt("Write ID: \n");
     trecord *foundUser = NULL;
 
     for(int i = 0; i < SIZE; i++) {
         if(strcmp(records[i].id, key)) {
             foundUser = &records[i];
 
             break;
         } 
     }
 
     return foundUser;
}

void printRecord(trecord *record) {
    printf("%s\n", record->id);
    printf("%s\n", record->firstName);
    printf("%s\n", record->lastName);
    printf("%s\n", record->address);
}

trecord* searchBySurname(trecord *records) {
    char *surname = prompt("Write ID: \n");

}