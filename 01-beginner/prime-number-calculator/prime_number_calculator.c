#include <stdio.h>

int main()
{
    //DECLARE VARIABLES
    int number = 0, rem01 = 0, rem02 = 0, rem03 = 0;
    
    //TAKE USER NUMBER
    printf("Enter Number : ");
    scanf("%d", &number);
    
    //CHECK WHETHER NUMBER IS 01
    if(number == 1)
    {
        printf("1 is NOT a Prime Number");
    }
    else
    {
        //PROCESS WHETHER NUMBER IS DIVISIBLE BY ITSELF
        rem01 = number % number;
        rem02 = number % 2;
        rem03 = number % 3;
        if(rem01 == 0 && (rem02 == 0 || rem03 == 0))
        {
            //OUTPUT RESULT
            printf("%d is NOT a Prime Number", number);
        }
        else
        {
            //OUTPUT RESULT
            printf("%d is a Prime Number", number);
        }
    }

    return 0;
}