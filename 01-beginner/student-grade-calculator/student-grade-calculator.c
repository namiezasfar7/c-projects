#include <stdio.h>
#include <string.h>

int main(){

    //DECLARE VARIABLES
    char studentName[50] = "";
    char grade = '\0';
    int total = 0;
    float average = 0.0f;

    //DECLARE ARRAY
    int marks[5] = {0};

    //GET USER INPUT
    printf("Enter Student Full Name : ");
    fgets(studentName, sizeof(studentName), stdin);
    studentName[strlen(studentName) - 1] = '\0';

    for(int i = 0; i < 5; i ++){

        printf("Enter Marks %d : ", i + 1);
        scanf("%d", &marks[i]);

        //GET TOTAL
        total += marks[i];
    }

    //CALCULATE AVERAGE
    average = (float)total / 5;

    //ASSIGN GRADE
    if(average >= 75){
        grade = 'A';
    }
    else if(average >= 65){
        grade = 'B';
    }
    else if(average >= 55){
        grade = 'C';
    }
    else if(average >= 45){
        grade = 'D';
    }
    else {
        grade = 'F';
    }

    //PRINT OUTPUT
    printf("\n====STUDENT REPORT====\n");
    printf("Student Full Name : %s\n", studentName);
    
    printf("Student Grades : ");
    for(int i = 0; i < 5; i ++){
        printf("%d\t", marks[i]);
    }

    printf("\nStudent Total : %d\n", total);
    printf("Student Average : %.2f\n", average);
    printf("Student Grade : %c\n", grade);

    return 0;
}