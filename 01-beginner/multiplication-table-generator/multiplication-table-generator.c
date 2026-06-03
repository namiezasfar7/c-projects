#include <stdio.h>

//DECLARE FUNCTION PROTOTYPE
void multiplicationTable(int number);

int main(){

    //DECLARE VARIABLES
    int number = 0;

    //GET USER INPUT
    printf("Enter Number : ");
    scanf("%d", &number);

    multiplicationTable(number);

    return 0;
}

void multiplicationTable(int number){

    //LOOP UNTIL CONDITION TRUE
    for(int i = 1; i < 16; i ++){

        //DECLARE VARIABLES
        int product = 0;

        //GET PRODUCT
        product = number * i;

        //PRINT OUTPUT
        printf("\n%02d x %02d = %d", number, i, product);
    }
}