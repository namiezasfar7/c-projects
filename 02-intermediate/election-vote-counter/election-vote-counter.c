#include <stdio.h>

//FUNCTION PROTOTYPES
void getVotes(int votes[], int size);

void calculateVotes(int votes[], int results[], float resultsPercentage[], int size);

int findWinner(int results[]);

void saveVotes(int results[], float resultsPercentage[], int result);

void readVotes();

//MAIN FUNCTION
int main(){
    //DECLARE ARRAY
    int votes[30] = {0};
    int results[3] = {0};
    float resultsPercentage[3] = {0};

    //DECLARE VARIABLES
    int result = 0, size = 30;

    //GET USER INPUT
    getVotes(votes, size);

    //COUNT VOTES
    calculateVotes(votes, results, resultsPercentage, size);

    //FIND WINNER
    result = findWinner(results);

    //SAVE TO FILE
    saveVotes(results, resultsPercentage, result);

    //READ FILE
    readVotes();

    //PRINT END MESSAGE
    printf("\nProgram Completed Successfully!");

    return 0;
}

//OTHER FUNCTIONS
void getVotes(int votes[], int size){
    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < size; i ++){
        //GET USER INPUT
        printf("\n====VOTING CANDIDATES====\n");
        printf("1. Alice\n");
        printf("2. Bob\n");
        printf("3. Charlie\n");

        printf("\nEnter Choice : ");
        scanf("%d", &votes[i]);

        //CHECK VALIDITY
        if(votes[i] < 1 || votes[i] > 3){
            printf("Invalid Choice! Try Again!");
            i --;
        }
    }
}

void calculateVotes(int votes[], int results[], float resultsPercentage[], int size){
    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < size; i ++){
        //CALCULATE VOTES
        if(votes[i] == 1){
            results[0] ++;
        }
        else if(votes[i] == 2){
            results[1] ++;
        }
        else{
            results[2] ++;
        }
    }

    //FIND VOTES PERCENTAGE
    resultsPercentage[0] = ((float) results[0] / size) * 100;
    resultsPercentage[1] = ((float) results[1] / size) * 100;
    resultsPercentage[2] = ((float) results[2] / size) * 100;
}

int findWinner(int results[]){
    //THREE WAY TIE
    if(results[0] == results[1] && results[1] == results[2]){
        return 0;
    }

    //ALICE & BOB TIE
    else if(results[0] == results[1] && results[0] > results[2]){
        return 0;
    }

    //ALICE & CHARLIE TIE
    else if(results[0] == results[2] && results[0] > results[1]){
        return 0;
    }

    //BOB & CHARLIE TIE
    else if(results[1] == results[2] && results[1] > results[0]){
        return 0;
    }

    //ALICE WINS
    else if(results[0] > results[1] && results[0] > results[2]){
        return 1;
    }

    //BOB WINS
    else if(results[1] > results[0] && results[1] > results[2]){
        return 2;
    }

    //CHARLIE WINS
    else{
        return 3;
    }
}

void saveVotes(int results[], float resultsPercentage[], int result){
    //OPEN FILE
    FILE *pFile = fopen("votes.txt", "w");

    if(pFile == NULL){
        printf("Cannot Create File\n");
        return;
    }

    //WRITE FILE
    fprintf(pFile, "\n====VOTING RESULTS====\n");
    fprintf(pFile, "Alice : %d (%.1f%%)\n", results[0], resultsPercentage[0]);
    fprintf(pFile, "Bob : %d (%.1f%%)\n", results[1], resultsPercentage[1]);
    fprintf(pFile, "Charlie : %d (%.1f%%)\n", results[2], resultsPercentage[2]);

    //PRINT WINNER
    if(result == 0){
        fprintf(pFile, "\nIt's a Tie!");
    }
    else if(result == 1){
        fprintf(pFile, "\nWinner: Alice");
    }
    else if(result == 2){
        fprintf(pFile, "\nWinner: Bob");
    }
    else{
        fprintf(pFile, "\nWinner: Charlie");
    }

    //CLOSE FILE
    fclose(pFile);
}

void readVotes(){
    //OPEN FILE
    FILE *pFile = fopen("votes.txt", "r");
    char buffer[1024] = {0};

    if(pFile == NULL){
        printf("Cannot Open File\n");
        return;
    }

    //READ FILE
    while(fgets(buffer, sizeof(buffer), pFile) != NULL){
        printf("%s", buffer);
    }

    //CLOSE FILE
    fclose(pFile);
}