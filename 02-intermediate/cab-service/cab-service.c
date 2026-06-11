#include <stdio.h>

//DECLARE VARIABLES
int packType = 0, distance = 0;
char payType = '\n';

//FUNCTION PROTOTYPE
void takeInput();
float calTotal(int packType, char payType, int distance);
void printOutput(float totalBill);

//MAIN FUNCTION
int main(){
    //DECLARE VARIABLES
    float totalBill = 0.0f;

    //GET USER INPUT
    takeInput();

    //CALCULATE TOTAL
    totalBill = calTotal(packType, payType, distance);

    //PRINT OUTPUT
    printOutput(totalBill);

    return 0;
}

//OTHER FUNCTIONS
void takeInput(){
    //GET USER INPUT
    printf("1 - Normal Meter Hires\n");
    printf("2 - Package Tours\n");
    printf("\nEnter Package Type : ");
    scanf("%d", &packType);

    printf("\nC - Cash\n");
    printf("D - Card\n");
    printf("\nEnter Payment Method : ");
    scanf(" %c", &payType);

    printf("\nEnter Distrance in KM : ");
    scanf("%d", &distance);
}

float calTotal(int packType, char payType, int distance){
    //DECLARE VARIABLES
    int kmCharge = 0;
    float finalBill = 0.0f, totalBill = 0.0f, addCharge = 0.0f, addAmt = 0.0f;

    switch(packType){
        case 1:
            kmCharge = 35;
            break;
        case 2:
            kmCharge = 40;
            break;
        default:
            printf("\nInvalid Package!");
            return 0.0f;
    }

    switch(payType){
        case 'C':
            addCharge = 0.0;
            break;
        case 'D':
            addCharge = 0.3;
            break;
        default:
            printf("\nInvalid Payment Method");
            return 0.0f;
    }

    //CALCULATE TOTAL BILL
    totalBill = (float) distance * kmCharge;
    
    //CALCULATE ADDITIONAL CHARGE
    addAmt = totalBill * addCharge;

    //CALCULATE FINAL BILL
    finalBill = totalBill + addAmt;

    return finalBill;
}

void printOutput(float totalBill){
    printf("\nTotal Charge is %.2f", totalBill);
}