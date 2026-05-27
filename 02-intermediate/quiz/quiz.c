#include <stdio.h>
#include <ctype.h>

//MAIN FUNCTION
int main() {
    char questions[][200] = {"What does CPU stand for?",
                            "Which number system does a computer mainly use?",
                            "Which device is used to type text into a computer?",
                            "What does RAM stand for?"};
    
    char options[][200] = {"A) Central Process Unit\nB) Central Processing Unit\nC) Computer Personal Unit\nD) Central Program Utility",
                           "A) Decimal\nB) Binary\nC) Octal\nD) Roman",
                           "A) Monitor\nB) Mouse\nC) Keyboard\nD) Printer",
                           "A) Read Access Memory\nB) Random Access Memory\nC) Run Access Memory\nD) Random Actual Memory"};
    
    char answerKey[] = {'B', 'B', 'C', 'B'};

    //CALCULATE SIZE OF ARRAY
    int questionCount = sizeof(questions) / sizeof(questions[0]);

    //DECLARE VARIABLES
    char answer = '\0';
    int score = 0;

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < questionCount; i ++){
        printf("\n%s\n", questions[i]);
        printf("\n%s\n", options[i]);

        printf("\nWhats Your Answer? : ");
        scanf(" %c", &answer);

        //MAKE ANSWER UPPER CASE
        answer = toupper(answer);

        if(answer == answerKey[i]){
            printf("CORRECT!");
            score ++;
        }
        else{
            printf("WRONG!");
        }
    }

    //PRINT RESULT
    printf("\nYou Scored %d out of %d Questions", score, questionCount);

    return 0;
}