#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DECLARE STRUCT
typedef struct {

    char passengerName[50];
    char NIC[20];
    int seatNumber;
    int routeNumber;
    char booked;

} Passenger;

//FUNCTION PROTORTYPES
void bookSeat(Passenger passengers[], int count);

void cancelSeat(Passenger passengers[], int count);

void searchPassenger(Passenger passengers[], int count);

void viewPassenger(Passenger passengers[], int count);

void saveFile(Passenger passengers[], int count);

void loadFile();

//MAIN FUNCTION
int main(){

    //DECLARE VARIABLES
    int passengerCount = 0;
    int choice = 0;
    int count = 0;

    //GET PASSENGER COUNT
    printf("Enter Passenger Count : ");
    scanf("%d", &passengerCount);

    //CHECK VALIDITY
    if(passengerCount <= 0){
        printf("Invalid Count!\n");
        return 1;
    }

    //ALLOCATE MEMORY
    Passenger *passengers = malloc(passengerCount * sizeof(Passenger));

    //RETURN ERROR IF MEMORY ALLOCATION FAILED
    if(passengers == NULL){
        printf("\nMemory Allocation Failed!");
        return 1;
    }

    printf("\n**********************\n");
    printf("BUS RESERVATION SYSTEM\n");
    printf("**********************\n");

    //LOOP UNTIL CONDITION IS TRUE
    do {

        //PRINT MENU SCREEN
        printf("1. Book Seat\n");
        printf("2. Cancel Seat\n");
        printf("3. Search Passenger\n");
        printf("4. View Passengers\n");
        printf("5. Save to File\n");
        printf("6. Load File\n");
        printf("7. Exit\n");

        //GET USER INPUT
        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        //CHECK CHOICE
        switch(choice){

            case 1:

                //CHECK AVAILABILITY
                if(count >= passengerCount){
                    printf("All Seats Booked!\n");
                }
                else{
                    //SEND TO FUNCTION
                    bookSeat(passengers, count);

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
                viewPassenger(passengers, count);

                break;

            case 5:

                //SEND TO FUNCTION
                saveFile(passengers, count);

                break;

            case 6:

                //SEND TO FUNCTION
                loadFile();

                break;

            case 7:

                //PRINT MESSAGE
                printf("Thank You For Using This System!\n");
                break;

            default:

                //PRINT MESSAGE
                printf("Invalid Choice! Try Again!\n");
        }

    } while(choice != 7);

    //FREE MEMORY
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

    getchar();

    //CHECK DUPLICATE SEATS
    for(int i = 0; i < count; i ++){

        if(passengers[i].seatNumber == seat && passengers[i].booked == 'Y'){
            printf("Seat Already Booked!\n");
            return;
        }
    }

    passengers[count].seatNumber = seat;

    printf("Enter Passenger Name : ");
    fgets(passengers[count].passengerName, sizeof(passengers[count].passengerName), stdin);
    passengers[count].passengerName[strcspn(passengers[count].passengerName,"\n")] = '\0';

    printf("Enter NIC Number : ");
    scanf("%s", passengers[count].NIC);

    printf("Enter Route Number : ");
    scanf("%d", &passengers[count].routeNumber);

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
            strcpy(passengers[i].passengerName, "");
            strcpy(passengers[i].NIC, "");
            passengers[i].routeNumber = 0;

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
    char NICNum[20] = "";

    //GET USER INPUT
    printf("\nEnter NIC Number : ");
    scanf("%s", NICNum);

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < count; i ++){

        //CHECK CONDITION
        if(strcmp(passengers[i].NIC, NICNum) == 0){

            //PRINT OUTPUT
            printf("\nPassenger Found\n");
            printf("Passenger Name  : %s\n", passengers[i].passengerName);
            printf("Passenger NIC   : %s\n", passengers[i].NIC);
            printf("Seat Number     : %d\n", passengers[i].seatNumber);
            printf("Route Number    : %d\n", passengers[i].routeNumber);
            printf("Booked          : %c\n", passengers[i].booked);

            return;
        }
    }

    //PRINT CONFIRMATION MESSAGE
    printf("Passenger Not Found!\n");
}

//VIEW PASSENGERS
void viewPassenger(Passenger passengers[], int count){

    //PRINT OUTPUT
    printf("\n*********** SEATS ***********\n");

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < count; i ++){

        printf("\nSeat Number      : %d\n", passengers[i].seatNumber);
        printf("Passenger Name   : %s\n", passengers[i].passengerName);
        printf("Passenger NIC    : %s\n", passengers[i].NIC);
        printf("Route Number     : %d\n", passengers[i].routeNumber);
        printf("Booked           : %c\n", passengers[i].booked);
    }
}

//SAVE TO FILE
void saveFile(Passenger passengers[], int count){

    //OPEN FILE
    FILE *pFile = fopen("bus.txt", "w");

    //CHECK VALIDITY
    if(pFile == NULL){
        printf("Cannot Create File!\n");
        return;
    }

    //SAVE TO FILE
    fprintf(pFile, "**********************\n");
    fprintf(pFile, "BUS RESERVATION SYSTEM\n");
    fprintf(pFile, "**********************\n\n");

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < count; i ++){

        fprintf(pFile, "Passenger %d\n",i+1);
        fprintf(pFile, "Passenger Name  : %s\n", passengers[i].passengerName);
        fprintf(pFile, "Passenger NIC   : %s\n", passengers[i].NIC);
        fprintf(pFile, "Seat Number     : %d\n", passengers[i].seatNumber);
        fprintf(pFile, "Route Number    : %d\n", passengers[i].routeNumber);
        fprintf(pFile, "Booked          : %c\n", passengers[i].booked);
        fprintf(pFile, "\n");
    }

    //CLOSE FILE
    fclose(pFile);

    //PRINT CONFIRMATION MESSAGE
    printf("Saved Successfully!\n");
}

//LOAD FROM FILE
void loadFile(){

    //OPEN FILE
    FILE *pFile = fopen("bus.txt", "r");
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