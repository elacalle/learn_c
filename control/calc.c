#include<stdio.h>

float perform(int, float, float);
int isValidOption(int);
float add(float, float);
float substract(float, float);
float multiply(float, float);
float divide(float, float);

void calc()
{
    int command = 0;
    float input1 = 0.0, input2 = 0.0, result = 0.0;

    do
    {
        system("clear");
        printf("1. Add: \n");
        printf("2. Substract: \n");
        printf("3. Multiply: \n");
        printf("4. Divide: \n");
        printf("5. Exit: \n");
        printf("Select an option: \n");

        scanf("%d", &command);

        if(command == 5) {
            break;
        }

        if(isValidOption(command)) {
            printf("Data 1: ");
            scanf("%f", &input1);

            printf("Data 2: ");
            scanf("%f", &input2);

            result = perform(command, input1, input2);

            printf("Result = %.2f \n", result);
            printf("Press any key to continue.");
            scanf("%*c%c");
        }

        if(!isValidOption(command) && command != 0) {
            system("clear");
            printf("Wrong command, write a valid command, press any key to continue.");
            scanf("%*c%c");
        }

        command = 0;
        input1 = 0.0;
        input2 = 0.0;
        result = 0.0;
    }
    while(1);
}

int isValidOption(int command) {
    int isValid = 0;

    switch(command) {
        case 1:
        case 2:
        case 3:
        case 4:
            isValid = 1;
        break;
    }

    return isValid;
}

float perform(int option, float input1, float input2)
{
    float result = 0.0;

    switch(option)
    {
    case 1:
        result = add(input1, input2);
        break;
    case 2:
        result = substract(input1, input2);
        break;
    case 3:
        result = multiply(input1, input2);
        break;
    case 4:
        result = divide(input1, input2);
        break;
    }

    return result;
}


float add(float input1, float input2)
{
    return input1 + input2;
}

float substract(float input1, float input2)
{
    return input1 - input2;
}

float multiply(float input1, float input2)
{
    return input1 * input2;
}

float divide(float input1, float input2)
{
    return input1 / input2;
}
