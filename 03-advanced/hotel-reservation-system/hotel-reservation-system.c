#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DECLARE STRUCT
struct Room {
    int roomNo;
    char name[50];
    int dayStaying;
    char occupied;
    int finalBill;
};

//FUNCTION PROTOTYPES
int reserveRoom(struct Room room[], int index);

int checkout(struct Room room[], int count);

void viewRooms(struct Room room[], int count);

void saveFile(struct Room room[], int count);

void readFile();

//MAIN FUCNTION
int main(){
    //DECLARE VARIABLES
    int size = 20, choice = 0, count = 0;
    int finalBill = 0;

    //CREATE ARRAY
    struct Room room[20] = {0};

    //PRINT HEADING
    printf("=================HOTEL RESERVATION SYSTEM=================\n");

    //LOOP UNTIL CONDITION IS TRUE
    do{
        //PRINT MENU
        printf("\n1. Reserve Room---------------------------------------------\n");
        printf("2. Checkout-------------------------------------------------\n");
        printf("3. View Rooms-----------------------------------------------\n");
        printf("4. Save File------------------------------------------------\n");
        printf("5. Load File------------------------------------------------\n");
        printf("6. Exit-----------------------------------------------------\n");

        //GET USER INPUT
        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(count >= size){
                    printf("Rooms Full!\n");
                }
                else{
                    //SEND TO FUNCTION
                    if(reserveRoom(room, count)){
                        //ADD COUNT
                        count++;
                    }
                }

                break;

            case 2:
                //SEND TO FUNCTION
                finalBill = checkout(room, count);

                //PRINT OUTPUT
                if(finalBill != -1){
                    printf("Final Bill Amount : Rs. %d\n", finalBill);
                }

                break;

            case 3:
                //SEND TO FUNCTION
                viewRooms(room, count);

                break;

            case 4:
                //SEND TO FUNCTION
                saveFile(room, count);

                break;

            case 5:
                //SEND TO FUNCTION
                readFile();

                break;

            case 6:
                printf("\nThank You For Using This System!\n");

                break;
                
            default:
                printf("\nInvalid Choice! Try Again!\n");
        }

    }while(choice != 6);

    return 0;
}

//OTHER FUNCTIONS
int reserveRoom(struct Room room[], int index){
    //GET USER INPUT
    printf("\n========================RESERVE ROOM========================\n");

    printf("\nEnter Room Number   : "):
    scanf("%d", &room[index].roomNo);
    getchar();

    //CHECK DUPLICATES
    for(int i = 0; i < index; i ++) {
        if(room[i].roomNo == room[index].roomNo && room[i].occupied == 'Y'){
            printf("Room already Occupied!\n");

            return 0;
        }
    }

    printf("Enter Customer Name : ");
    fgets(room[index].name, sizeof(room[index].name), stdin);
    room[index].name[strcspn(room[index].name, "\n")] = '\0';

    printf("\nEnter Days Staying  : ");
    scanf("%d", &room[index].dayStaying);

    //UPDATE ROOM STATUS & BILL
    room[index].occupied = 'Y';
    room[index].finalBill = 0;

    //GIVE CONFIRMATION MESSAGE
    printf("Room Reserved Successfully!\n");

    return 1;
}

int checkout(struct Room room[], int count){
    //DECLARE VARIABLES
    int id = 0;

    //GET USER INPUT
    printf("\n===========================CHECKOUT==========================\n");

    printf("\nEnter Room Number   : ");
    scanf("%d", &id);

    for(int i = 0; i < count; i ++) {
        if(room[i].roomNo == id && room[i].occupied == 'Y'){
            //UPDATE ROOM STATUS
            room[i].occupied = 'N';

            //CALCULATE BILL
            room[i].finalBill = room[i].dayStaying * 20000;

            return room[i].finalBill;

            break;
        }
    }

    printf("Room Not Found!\n");

    return -1;
}

void viewRooms(struct Room room[], int count){
    //PRINT OUTPUT
    printf("\n=========================ROOM STATUS=========================\n\n");
    
    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < count; i ++){
        printf("\nRoom Number     : %d\n",room[i].roomNo);
        printf("Customer Name   : %s\n",room[i].name);
        printf("Days Staying    : %d\n",room[i].dayStaying);
        printf("Is Occupied     : %c\n",room[i].occupied);
    }
}

void saveFile(struct Room room[], int count){
    //CREATE FILE
    FILE *pFile = fopen("rooms.txt", "w");

    if(pFile == NULL){
        printf("Cannot Create File!");
        return;
    }

    //SAVE TO FILE
    fprintf(pFile, "=================HOTEL RESERVATION SYSTEM=================\n\n");

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < count; i ++){
        fprintf(pFile, "Room Number     : %d\n", room[i].roomNo);
        fprintf(pFile, "Customer Name   : %s\n", room[i].name);
        fprintf(pFile, "Days Staying    : %d\n", room[i].dayStaying);
        fprintf(pFile, "Is Occupied     : %c\n", room[i].occupied);
        fprintf(pFile, "\nFinal Bill      : %d\n", room[i].finalBill);
        fprintf(pFile, "-------------------------------------------------------------");
        fprintf(pFile, "\n\n");
    }

    //CLOSE FILE
    fclose(pFile);

    //CONFIRMATION MESSAGE
    printf("Saved successfully!\n");
}

void readFile(){
    //CREATE FILE
    FILE *pFile = fopen("rooms.txt", "r");
    
    //DECLARE BUFFER
    char buffer[1024] = {0};

    if(pFile == NULL){
        printf("Cannot Open File!");
        return;
    }

    while(fgets(buffer, sizeof(buffer), pFile) != NULL){
        printf("%s", buffer);
    }

    //CLOSE FILE
    fclose(pFile);
}