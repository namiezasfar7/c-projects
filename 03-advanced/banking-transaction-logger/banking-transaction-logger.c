#include <stdio.h>

//FUNCTION PROTOTYPE
void deposit(float *balance, float amount);

void withdraw(float *balance, float amount);

void saveTransaction(FILE *fp,
                     char transaction[],
                     float amount,
                     float balance);

//MAIN FUNCTION
int main(){
    //DECLARE VARIABLES
    int choice = 0;
    float balance = 0.0f, amount = 0.0f;

    //OPEN FILE
    FILE *fp = fopen("transactions.txt", "a");

    if(fp == NULL){
        printf("Cannot Open File!\n");
        return 1;
    }

    
    //LOOP UNTIL CONDITION IS TRUE
    do{
        //GET USER INPUT
        printf("\n==== BANK SYSTEM ====\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");

        printf("\nWhats Your Choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                //GET USER INPUT
                printf("Enter Deposit Amount : Rs. ");
                scanf("%f", &amount);

                //CHECK VALIDITY
                if(amount <= 0){
                    printf("Invalid Amount!\n");
                    break;
                }

                //SEND TO FUNCTION
                deposit(&balance, amount);

                //EDIT FILE
                saveTransaction(fp, "Deposit", amount, balance);
                break;

            case 2:
                //GET USER INPUT
                printf("Enter Withdraw Amount : Rs. ");
                scanf("%f", &amount);

                //CHECK VALIDITY
                if(amount <= 0){
                    printf("Invalid Amount!\n");
                    break;
                }

                //SEND TO FUNCTION
                withdraw(&balance, amount);

                //EDIT FILE
                saveTransaction(fp, "Withdraw", amount, balance);
                break;

            case 3:
                printf("\nCurrent Balance : Rs. %.2f", balance);
                break;

            case 4:
                printf("\nThank You For Using This System!\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again");
        }

    }while(choice != 4);

    //CLOSE FILE
    fclose(fp);

    return 0;
}

//OTHER FUNCTIONS
void deposit(float *balance, float amount){

    *balance += amount;

}

void withdraw(float *balance, float amount){

    if(amount > *balance){
        printf("Insufficient Balance!\n");
        return;
    }

    *balance -= amount;
}

void saveTransaction(FILE *fp,
                     char transaction[],
                     float amount,
                     float balance){

    fprintf(fp,"%s : Rs. %.2f\n", transaction, amount);
    fprintf(fp,"Balance : Rs. %.2f\n\n", balance);

}