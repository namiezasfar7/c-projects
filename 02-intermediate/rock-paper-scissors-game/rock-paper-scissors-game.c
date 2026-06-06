#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){

    //DECLARE VARIABLES
    int choice = 0;
    int min = 1, max = 3;
    char choiceName[10] = "";
    char computerName[10] = "";

    char options[3][10] = {"Rock", "Paper", "Scissors"};

    //RANDOM SEED
    srand(time(NULL));
    
    //RANDOM PSEUDO-NUMBER GENERATOR
    int computer = (rand() % (max - min + 1)) + min;

    //GET USER INPUT
    printf("===ROCK PAPER SCISSORS===");
    printf("\n1. Rock");
    printf("\n2. Paper");
    printf("\n3. Scissors");
    printf("\nWhats Your Choice : ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            strcpy(choiceName, options[0]);
            break;
        case 2:
            strcpy(choiceName, options[1]);
            break;
        case 3:
            strcpy(choiceName, options[2]);
            break;
    }

    switch(computer){
        case 1:
            strcpy(computerName, options[0]);
            break;
        case 2:
            strcpy(computerName, options[1]);
            break;
        case 3:
            strcpy(computerName, options[2]);
            break;
    }

    //CHECK CONDITION & PRINT RESULT
    if((choice == 1 && computer == 3) || (choice == 2 && computer == 1) || (choice == 3 && computer == 2)){
        printf("\nYou Chose %s", choiceName);
        printf("\nComputer Chose %s", computerName);
        printf("\nYou Win!");
    }
    else{
        printf("\nYou Chose %s", choiceName);
        printf("\nComputer Chose %s", computerName);
        printf("\nYou Lose!");
    }

    return 0;
}