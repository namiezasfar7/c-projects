#include <stdio.h>

int main()
{
    //DECLARE VARIABLES
    int count = 1, number = 0, sum = 0;
    
    //GET INPUTS
    printf("Input Number [N] : ");
    scanf("%d", &number);
    
    //LOOP UNTIL CONDITION IS TRUE
    while(count <= number)
    {
        sum += count;
        count ++;
    }
    
    //PRINT OUTPUT
    printf("Sum of [N] Number of Numbers : %d", sum);

    return 0;
}