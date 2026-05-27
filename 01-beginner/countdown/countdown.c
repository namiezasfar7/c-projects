#include <stdio.h>

int main()
{
    //DECLARE VARIABLES
    int count = 0, number = 0;
    
    //TAKE USER INPUT
    printf("Enter Number : ");
    scanf("%d", &number);
    
    //LOOP UNTIL CONDITION IS TRUE
    while(number >= count)
    {
        //PRINT OUTPUT
        printf("%d\t", number);
        number -= 1;
    }

    return 0;
}