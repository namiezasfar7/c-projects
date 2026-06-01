#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){

    //DECLARE VARIABLES
    int choice = 0, number = 0;
    int min = 1, max = 6;

    //RANDOM SEED
    srand(time(NULL));

    //LOOP UNTIL CONDITION IS TRUE
    do{

        //GET USER INPUT
        printf("\n----DICE ROLLING SIM---\n");
        printf("\n1. Roll Dice\n");
        printf("2. Exit\n");
        
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        if(choice == 1){
            //GENERATE RANDOM PSEUDO-NUMBER
            number = (rand() % (max - min + 1)) + min;

            //PRINT OUTPUT
            printf("\nYou rolled %d\n", number);
        }
        else if(choice != 2){
            printf("Invalid Choice!\n");
        }

    }while(choice != 2);

    return 0;
}