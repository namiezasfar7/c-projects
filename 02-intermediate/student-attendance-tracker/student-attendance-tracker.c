#include <stdio.h>
#include <stdlib.h>

int main(){

    //DECLARE VARIABLES
    int studentCount = 0, studentsPresent = 0, studentsAbsent = 0;
    float attendancePercentage = 0.0f;

    //GET USER INPUT
    printf("How many students? : ");
    scanf("%d", &studentCount);

    //CHECK VALIDITY
    if (studentCount <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    //ALLOCATE MEMORY FOR STUDENT COUNT
    char *attendance = malloc(studentCount * sizeof(char));

    //RETURN ERROR IF MEMORY ALLOCATION FAILED
    if(attendance == NULL){
        printf("\nMemory Allocation Failed!");
        return 1;
    }

    printf("\nP - Present | A - Absent\n");

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < studentCount; i ++){

        //GET USER INPUT
        printf("Enter Attendance of Student %d : ", i + 1);
        scanf(" %c", &attendance[i]);

        //GET ATTENDANCE COUNT
        if (attendance[i] == 'P' || attendance[i] == 'p') {
            studentsPresent ++;
        }
        else if (attendance[i] == 'A' || attendance[i] == 'a') {
            studentsAbsent ++;
        }
        else {
            printf("Invalid input! Enter P or A only.\n");
            i--;
        }
    }

    //GET ATTENDANCE PERCENTAGE
    attendancePercentage = ((float) studentsPresent / studentCount) * 100.0f;

    //PRINT OUTPUT
    printf("\n\nPresent Students : %d", studentsPresent);
    printf("\nAbsent Students : %d", studentsAbsent);
    printf("\nAttendance Percentage : %.2f Percent", attendancePercentage);

    //FREE MEMORY
    free(attendance);
    attendance = NULL;

    return 0;
}