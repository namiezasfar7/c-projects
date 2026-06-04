#include <stdio.h>

//FUNCTION PROTOTYPES
float add(float num01, float num02);
float subtract(float num01, float num02);
float multiply(float num01, float num02);
float divide(float num01, float num02);

int main(){

    //DECLARE VARIABLES
    int choice = 0;
    float num01 = 0.0f, num02 = 0.0f;

    printf("====CALCULATOR====\n");
    do {

        float result = 0.0f;
        char operation = '\0';

        //SHOW MENU
        printf("\n1. Add");
        printf("\n2. Subtract");
        printf("\n3. Multiply");
        printf("\n4. Divide");
        printf("\n5. Exit\n");

        //GET USER INPUT
        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        //EXIT BEFORE ASKING FOR NUMBERS
        if(choice == 5){
            printf("\nThank You For Using the Calculator!\n");
            break;
        }

        // INVALID CHOICE
        if(choice < 1 || choice > 5){
            printf("\nInvalid Choice!\n");
            continue;
        }

        printf("\nEnter Number 01 : ");
        scanf("%f", &num01);
        printf("Enter Number 02 : ");
        scanf("%f", &num02);

        switch(choice){
            case 1:
                operation = '+';
                result = add(num01, num02);
                break;
            case 2:
                operation = '-';
                result = subtract(num01, num02);
                break;
            case 3:
                operation = 'x';
                result = multiply(num01, num02);
                break;
            case 4:
                if(num02 == 0)
                {
                    printf("\nCannot divide by zero!\n");
                    continue;
                }
                operation = '/';
                result = divide(num01, num02);
                break;
        }

        //PRINT OUTPUT
        printf("\n%.2f %c %.2f = %.2f\n", num01, operation, num02, result);

    } while(choice != 5);

    return 0;
}

float add(float num01, float num02){
    return num01 + num02;
}

float subtract(float num01, float num02){
    return num01 - num02;
}

float multiply(float num01, float num02){
    return num01 * num02;
}

float divide(float num01, float num02){
    return num01 / num02;
}