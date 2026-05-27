#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//MAIN FUNCTION
int main(){
    //DECLARE VARIABLES
    int guess = 0, tries = 0;
    int min = 1, max = 100;
    
    //RANDOM SEED
    srand(time(NULL));
    
    //RANDOM PSEUDO-NUMBER GENERATOR
    int answer = (rand() % (max - min + 1)) + min;
    
    printf("---NUMBER GUESSING GAME---\n");
    
    //LOOP UNTIL ANSWER IS CORRECT
    do{
        //GET USER INPUT
        printf("Guess a Number Between %d - %d : ", min, max);
        scanf("%d", &guess);
        tries ++;
        
        //GIVE HINTS
        if(guess > answer){
            printf("TOO HIGH!\n");
        }
        else if(guess < answer){
            printf("TOO LOW!\n");
        }
        else{
            printf("CORRECT!\n");
        }
        
    }while(guess != answer);
    
    //PRINT OUTPUT
    printf("The Answer is %d", answer);
    printf("\nIt Took You %d Tries", tries);
    
    return 0;
}