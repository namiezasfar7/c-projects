#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//DECLARE STRUCT
typedef struct {
    char passportNumber[20];
    char name[50];
    int seatNumber;
    char destination[30];
    char booked;
} Passenger;

//FUNCTION PROTOTYPES
void bookSeat(Passenger passengers[], int count);

void cancelSeat(Passenger passengers[], int count);

void searchPassenger(Passenger passengers[], int count);

void viewSeats(Passenger passengers[], int count);

void saveFile(Passenger passengers[], int count);

void loadFile();

//MAIN FUNCTION
int main(){

    //DECLARE VARIABLES
    int seatCount = 0;
    int choice = 0;
    int count = 0;
    bool isRunning = true;

    //GET USER INPUT FOR PASSENGER COUNT
    printf("***********************\n");
    printf("AIRLINE RESERVATION SYSTEM\n");
    printf("***********************\n");

    printf("Enter Seat Count : ");
    scanf("%d", &seatCount);

    if(employeeCount <= 0){
        printf("Invalid Seat Count!\n");
        return 1;
    }

    //CREATE ARRAY
    Passenger *passengers = malloc(seatCount * sizeof(Passenger));

    //RETURN ERROR IF MEMORY ALLOCATION FAILED
    if(passengers == NULL){
        printf("Memory Allocation Failed!\n");
        return 1;
    }

    //LOOP UNTIL CONDITION IS TRUE
    while(isRunning){

        //PRINT MENU
        printf("\n1. Book Seat\n");
        printf("2. Cancel Seat\n");
        printf("3. Search Passenger\n");
        printf("4. View Seats\n");
        printf("5. Save File\n");
        printf("6. Load File\n");
        printf("7. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch(choice){

            case 1:

                if(count >= size){
                    printf("No Seats Available!\n");
                }
                else{
                    //SEND TO FUNCTION
                    bookSeat(assengers, count);

                    //ADD COUNT
                    count ++;
                }

                break;

            case 2:

                //SEND TO FUNCTION
                cancelSeat(passengers, count);

                break;

            case 3:

                //SEND TO FUNCTION
                searchPassenger(passengers, count);

                break;

            case 4:

                //SEND TO FUNCTION
                viewSeats(passengers, count);

                break;

            case 5:

                //SEND TO FUNCTION
                saveFile(passengers, count);

                break;

            case 6:

                //CALL FUNCTION
                loadFile();

                break;

            case 7:

                //PRINT OUTPUT MESSAGE
                printf("Thank Four Using This System!\n");
                isRunning = false;

                break;

            default:

                //PRINT OUTPUT MESSAGE
                printf("Invalid Choice! Try Again!\n");
        }
    }

    //CLOSE & CLEAN ARRAY
    free(passengers);
    passengers = NULL;

    return 0;
}

//OTHER FUNCTIONS
//BOOK SEAT
void bookSeat(Passenger passengers[], int count){

    //DECLARE VARIABLES
    int seat = 0;

    //GET USER INPUT
    printf("\n*************************\n");
    printf("BOOK SEAT\n");
    printf("*************************\n");

    printf("Enter Seat Number : ");
    scanf("%d", &seat);

    //CHECK DUPLICATE SEATS
    for(int i = 0; i < count; i ++){

        if(passengers[i].seatNumber == seat && passengers[i].booked == 'Y'){
            printf("Seat Already Booked!\n");
            return;
        }
    }

    passengers[count].seatNumber = seat;

    printf("Enter Passport Number : ");
    scanf("%s", passengers[count].passportNumber);

    getchar();

    printf("Enter Passenger Name : ");
    fgets(passengers[count].name, sizeof(passengers[count].name), stdin);
    passengers[count].name[strcspn(passengers[count].name,"\n")] = '\0';

    printf("Enter Destination : ");
    fgets(passengers[count].destination, sizeof(passengers[count].destination), stdin);
    passengers[count].destination[strcspn(passengers[count].destination,"\n")] = '\0';

    //SET STATUS AS BOOKED
    passengers[count].booked = 'Y';

    //PRINT CONFIRMATION MESSAGE
    printf("\nSeat Booked Successfully!\n");
}

//CANCEL SEAT
void cancelSeat(Passenger passengers[], int count){

    //DECLARE VARIABLES
    int seat = 0;

    //GET USER INPUT
    printf("\nEnter Seat Number : ");
    scanf("%d", &seat);

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < count; i ++){

        if(passengers[i].seatNumber == seat && passengers[i].booked == 'Y'){

            //SET STATUS AS NOT BOOKED
            passengers[i].booked = 'N';
            passengers[i].seatNumber = 0;

            //CLEAR DETAILS
            strcpy(passengers[i].passportNumber, "");
            strcpy(passengers[i].name, "");
            strcpy(passengers[i].destination, "");

            printf("Seat Cancelled Successfully!\n");

            return;
        }
    }

    //PRINT CONFIRMATION MESSAGE
    printf("Seat Not Found!\n");
}

//SEARCH PASSENGER
void searchPassenger(Passenger passengers[], int count){

    //DECLARE VARIABLES
    char passport[20] = "";

    //GET USER INPUT
    printf("\nEnter Passport Number : ");
    scanf("%s", passport);

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < count; i ++){

        //CHECK CONDITION
        if(strcmp(passengers[i].passportNumber, passport) == 0){

            //PRINT OUTPUT
            printf("\nPassenger Found\n");
            printf("Passport Number : %s\n", passengers[i].passportNumber);
            printf("Passenger Name  : %s\n", passengers[i].name);
            printf("Seat Number     : %d\n", passengers[i].seatNumber);
            printf("Destination     : %s\n", passengers[i].destination);
            printf("Booked          : %c\n", passengers[i].booked);

            return;
        }
    }

    //PRINT CONFIRMATION MESSAGE
    printf("Passenger Not Found!\n");
}

//VIEW SEATS
void viewSeats(Passenger passengers[], int count){

    //PRINT OUTPUT
    printf("\n*********** SEATS ***********\n");

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < count; i ++){

        printf("\nSeat Number      : %d\n", passengers[i].seatNumber);
        printf("Passport Number  : %s\n", passengers[i].passportNumber);
        printf("Passenger Name   : %s\n", passengers[i].name);
        printf("Destination      : %s\n", passengers[i].destination);
        printf("Booked           : %c\n", passengers[i].booked);
    }
}

//SAVE TO FILE
void saveFile(Passenger passengers[], int count){

    //OPEN FILE
    FILE *pFile = fopen("airline.txt", "w");

    //CHECK VALIDITY
    if(pFile == NULL){
        printf("Cannot Create File!\n");
        return;
    }

    //SAVE TO FILE
    fprintf(pFile, "******************************\n");
    fprintf(pFile, "AIRLINE RESERVATION SYSTEM\n");
    fprintf(pFile, "******************************\n\n");

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < count; i ++){

        fprintf(pFile,"Passenger %d\n",i+1);
        fprintf(pFile,"Passport Number : %s\n", passengers[i].passportNumber);
        fprintf(pFile,"Passenger Name  : %s\n", passengers[i].name);
        fprintf(pFile,"Seat Number     : %d\n", passengers[i].seatNumber);
        fprintf(pFile,"Destination     : %s\n", passengers[i].destination);
        fprintf(pFile,"Booked          : %c\n", passengers[i].booked);
        fprintf(pFile,"\n");
    }

    //CLOSE FILE
    fclose(pFile);

    //PRINT CONFIRMATION MESSAGE
    printf("Saved Successfully!\n");
}

//LOAD FILE
void loadFile(){

    //OPEN FILE
    FILE *pFile = fopen("airline.txt", "r");
    char buffer[1024];

    //CHECK VALIDITY
    if(pFile == NULL){
        printf("Cannot Open File!\n");
        return;
    }

    //READ FROM FILE
    while(fgets(buffer, sizeof(buffer), pFile) != NULL){
        printf("%s", buffer);
    }

    //CLOSE FILE
    fclose(pFile);
}