#include <stdio.h>
#include <stdlib.h>

int main(){

    //DECLARE VARIABLES
    int days = 0, total = 0, min = 0, max = 0, highestDay = 0, lowestDay = 0;
    float avg = 0.0f;

    //GET USER INPUT
    printf("====HOSPITAL PATIENT MANAGER====\n");
    printf("\nHow Many Days? : ");
    scanf("%d", &days);

    //ALLOCATE MEMORY FOR PATIENT COUNT
    int *patientCount = malloc(days * sizeof(int));

    //RETURN ERROR IF MEMORY ALLOCATION FAILED
    if(patientCount == NULL){
        printf("\nMemory Allocation Failed!");
        return 1;
    }

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < days; i ++){

        //GET USER INPUT
        printf("\nEnter Patient Count on Day %d : ", i + 1);
        scanf("%d", &patientCount[i]);

        //ADD TOTAL
        total += patientCount[i];

        //SET DEFAULT MIN & MAX
        if(i == 0){
            min = patientCount[i];
            max = patientCount[i];

            lowestDay = i + 1;
            highestDay = i + 1;
        }

        //GET MAX AND MIN
        if(patientCount[i] < min){
            min = patientCount[i];
            lowestDay = i + 1;
        }

        if(patientCount[i] > max){
            max = patientCount[i];
            highestDay = i + 1;
        }
    }

    //GET AVERAGE PATIENTS
    avg = (float) total / days;

    //PRINT OUTPUT
    printf("\nPatient Count for %d : ", days);
    for(int i = 0; i < days; i ++){
        printf("%d ", patientCount[i]);
    }
    printf("\nTotal Patient Count : %d", total);
    printf("\nAverage Patient Count : %.2f", avg);
    printf("\nDay %d had the Most Number of Patients : %d", highestDay, max);
    printf("\nDay %d had the Least Number of Patients : %d", lowestDay, min);

    //FREE MEMORY
    free(patientCount);
    patientCount = NULL;

    return 0;
}