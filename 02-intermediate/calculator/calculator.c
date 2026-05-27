#include <stdio.h>

int main()
{
    //DECLARE VARIABLES
    float num01 = 0.0f, num02 = 0.0f, result = 0.0f;
    char operation = '\0';
    
    //GET USER INPUT
    printf("Enter Number 01 : ");
    scanf("%f", &num01);
    
    printf("Enter Operation [+ - * /] : ");
    scanf(" %c", &operation);
    
    printf("Enter Number 02 : ");
    scanf("%f", &num02);
    
    //RESULT CALCULATION
    switch(operation)
    {
        case '+':
            result = num01 + num02;
            break;
        case '-':
            result = num01 - num02;
            break;
        case '*':
            result = num01 * num02;
            break;
        case '/':
            //CHECK WHETHER DIVISION IS POSSIBLE
            if(num02 == 0)
            {
                printf("Cant divide by zero!");
            }
            else
            {
                result = num01 / num02;
            }
            break;
        default:
            printf("Invalid Operation");
    }
    
    //PRINT RESULT
    printf("\nResult : %.2f", result);

    return 0;
}