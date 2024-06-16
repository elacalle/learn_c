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
void write(trecord **records);
void printRecord(trecord record);

trecord* searchById(trecord **trecord);
trecord* searchBySurname(trecord **trecord);

typedef trecord* (*FuncPtr)();

int main() {
    int option = 0;
    trecord *records[SIZE] = { NULL };
    FuncPtr pfn[2] = { searchById, searchBySurname };

    while(true) {
        system("clear");
        menu();
        scanf("%d", &option);
        scanf("%*c");
    
        if(option < 1 || option > 4) {
            scanf("%*c");
            system("clear");

            printf("Invalid option, press any key to continue. \n");
            getchar();

        } else {
            if(option == 4) {
                break;
            } else if(option == 1) {
                write(records);
            } else {
                system("clear");
                trecord *output = (pfn[option - 2])(records);

                if(output != NULL) {
                    printf("Record found! \n");
                    printRecord(*output);
                } else {
                    printf("404 Record not found! \n");
                }

                scanf("%*c");
                printf("Press any key to continue. \n");
                getchar();
            }
        }
    }

    return 1;   
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
    char buffer[100];

    while(i < SIZE) {
        trecord *newRecord = malloc(sizeof(trecord));
        char option;

        printf("Enter your ID:\n");
        scanf("%s", newRecord->id);
        scanf("%*c");

        printf("Enter your first name:\n");
        scanf("%s", newRecord->firstName);
        scanf("%*c");

        printf("Enter your last name:\n");
        fgets(buffer, sizeof(buffer), stdin);
        strcpy(newRecord->lastName, buffer);
 
        printf("Enter your address:\n");
        scanf("%s", newRecord->address);
        scanf("%*c");
        
        records[i] = newRecord;
        i++;

        printf("Press s/n to continue..\n");
        option = getchar();

        if('n' == option) {
            break;
        }
    }
}

trecord* searchById(trecord **records) {
    char id[10];
    printf("Write the record ID:\n");
    scanf("%s", id);
    trecord *foundRecord = NULL; 

    for(int i = 0; i < SIZE; i++) {
        if(records[i] != NULL) {
            if(strcmp(records[i]->id, id) == 0) {
                foundRecord = records[i];
            } 
        }
    }

    return foundRecord;
}

void printRecord(trecord record) {
    printf("%s\n", record.id);
    printf("%s\n", record.firstName);
    printf("%s\n", record.lastName);
    printf("%s\n", record.address);
}

trecord* searchBySurname(trecord **records) {
    char lastName[30];
    printf("Write the record ID:\n");
    scanf("%s", lastName);

    for(int i = 0; i < SIZE; i++) {
        if(strcmp(records[i]->lastName, lastName) == 0) {
            return records[i];

            break;
        } 
    }

    return NULL;
}