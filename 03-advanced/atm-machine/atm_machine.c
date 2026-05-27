#include <stdio.h>

//FUNTION PROTOTYPE
void displayMenu();
int depositCash(int balance, int deposit);
int withdrawCash(int balance, int withdraw);

//MAIN FUNCTION
int main()
{
    //DECLARE VARIABLES
    int choice = 0, balance = 0, deposit = 0, withdraw = 0;
    
    while(choice != 04)
    {
        displayMenu();
    
        //TAKE USER INPUT
        printf("\nWhat's Your Choice? [01 02 03 04] : ");
        scanf("%d", &choice);
    
        switch(choice)
        {
            //CHECK BALANCE
            case 1:
                printf("\nYour Current Balance : Rs. %d\n", balance);
                break;
            
            //DEPOSIT CASH
            case 2:
                printf("\nEnter Deposit Amount : ");
                scanf("%d", &deposit);
                balance = depositCash(balance, deposit);
                break;
            
            //WITHDRAW CASH
            case 3:
                printf("\nEnter Withdraw Amount : ");
                scanf("%d", &withdraw);
                balance = withdrawCash(balance, withdraw);
                break;
            
            //EXIT
            case 04:
                printf("\nThank You For Using Our ATM!\n");
                break;
            
            //INVALID INPUT
            default:
                printf("\nInvalid Choice! Try Again!\n");
        }
    }

    return 0;
}

//DISPLAY MENU
void displayMenu()
{
    printf("\n====================");
    printf("\n    ATM MACHINE     ");
    printf("\n====================");
    printf("\n01. Check Balance");
    printf("\n02. Deposit");
    printf("\n03. Withdraw");
    printf("\n04. Exit");
}

//DEPOSIT FUNTION
int depositCash(int balance, int deposit)
{
    if(deposit <= 0)
    {
        printf("\nInvalid Deposit Amount!\n");
    }
    else
    {
        balance += deposit;
        printf("\nDeposit Successful!\n");
    }

    return balance;
}

//WITHDRAW FUNTION
int withdrawCash(int balance, int withdraw)
{
    if(withdraw > balance)
    {
        printf("\nInsufficient Funds!\n");
    }
    else
    {
        balance -= withdraw;
        printf("\nWithdrawal Successful!\n");
    }

    return balance;
}