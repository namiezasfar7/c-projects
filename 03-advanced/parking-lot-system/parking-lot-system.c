#include <stdio.h>

int main(){
    //DECLARE VARIABLES
    int choice = 0;

    //DECLARE ARRAY
    char parkingSpace[10] = {0};
    for(int i = 0; i < 10; i++){
        parkingSpace[i] = 'E';
    }

    do {
        //DECLARE VARIABLES
        int slot = 0;

        //GET USER INPUT
        printf("\n1. Park Car");
        printf("\n2. Remove Car");
        printf("\n3. View Slots");
        printf("\n4. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter Slot Number to Park In (1 - 10) : ");
                scanf("%d", &slot);
                if(slot < 1 || slot > 10)
                {
                    printf("Invalid Slot!\n");
                }
                else if(parkingSpace[slot - 1] == 'O')
                {
                    printf("Slot already occupied!\n");
                }
                else
                {
                    parkingSpace[slot - 1] = 'O';
                    printf("Car parked in slot %d\n", slot);
                }
                break;
            
            case 2:
                printf("\nEnter Slot Number to Remove (1-10): ");
                scanf("%d", &slot);

                if(slot < 1 || slot > 10)
                {
                    printf("Invalid Slot!\n");
                }
                else if(parkingSpace[slot - 1] == 'E')
                {
                    printf("Slot is already empty!\n");
                }
                else
                {
                    parkingSpace[slot - 1] = 'E';
                    printf("Car removed from slot %d\n", slot);
                }
                break;
            
            case 3:
                printf("\n--- PARKING STATUS ---\n");
                for(int i = 0; i < 10; i++)
                {
                    if(parkingSpace[i] == 'E')
                    {
                        printf("Slot %d : Empty\n", i + 1);
                    }
                    else
                    {
                        printf("Slot %d : Occupied\n", i + 1);
                    }
                }
                break;
            
            case 4:
                printf("\nThank You For Using Parking Lot System!\n");
                break;
            
            default:
                printf("\nInvalid Input!");
                continue;
        }
    } while(choice != 4);

    return 0;
}