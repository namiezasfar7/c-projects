#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DECLARE STRUCT
struct Student
{
    char id[20];
    char name[50];
    int marks[3];
    int total;
    float average;
    char grade;
};

//FUNCTION PROTOTYPE
void inputStudents(struct Student students[], int size);

void calculateResults(struct Student students[], int size);

void saveStudents(struct Student students[], int size);

void readStudents();

//MAIN FUNCTION
int main(){
    //DECLARE VARIABLES
    int size = 0;

    //GET NUMBER OF STUDENTS
    printf("Enter Number of Students : ");
    scanf("%d", &size);

    //CHECK VALIDITY
    if (size <= 0) {
        printf("Invalid number of Students.\n");
        return 1;
    }

    //ALLOCATE MEMORY FOR STUDENT COUNT
    struct Student *students = malloc(size * sizeof(struct Student));

    //RETURN ERROR IF MEMORY ALLOCATION FAILED
    if(students == NULL){
        printf("\nMemory Allocation Failed!");
        return 1;
    }

    //GET USER INPUT
    inputStudents(students, size);

    //CALCULATE RESULTS
    calculateResults(students, size);

    //SAVE TO FILE
    saveStudents(students, size);

    //READ FILE
    readStudents();

    //FREE MEMORY
    free(students);
    students = NULL;

    return 0;
}

//OTHER FUNCTIONS
void inputStudents(struct Student students[], int size){
    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < size; i ++){
        //GET USER INPUT
        printf("Enter Student ID : ");
        scanf("%s", students[i].id);

        getchar();

        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        for(int j = 0; j < 3; j ++){
            printf("Enter Marks %d : ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }
    }
}

void calculateResults(struct Student students[], int size){
    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < size; i ++){
        //INITIALIZE TOTAL
        students[i].total = 0;

        //CALCULATE TOTAL
        for(int j = 0; j < 3; j ++){
            students[i].total += students[i].marks[j];
        }

        //CALCULATE AVERAGE
        students[i].average = (float) students[i].total / 3;

        //CALCULATE GRADE
        if(students[i].average >= 75){
            students[i].grade = 'A';
        }
        else if(students[i].average >= 65){
            students[i].grade = 'B';
        }
        else if(students[i].average >= 55){
            students[i].grade = 'C';
        }
        else if(students[i].average >= 45){
            students[i].grade = 'D';
        }
        else{
            students[i].grade = 'W';
        }
    }
}

void saveStudents(struct Student students[], int size){
    //OPEN FILE
    FILE *pFile = fopen("students.txt", "w");

    if(pFile == NULL){
        printf("Cannot Create File!\n");
        return;
    }

    //SAVE TO FILE
    for(int i = 0; i < size; i ++){
        fprintf(pFile, "\n=== Student %d ===\n", i + 1);
        fprintf(pFile, "Student ID : %s\n", students[i].id);
        fprintf(pFile, "Student Name : %s\n", students[i].name);
        
        for(int j = 0; j < 3; j ++){
            fprintf(pFile, "Marks %d : %d\n", j + 1, students[i].marks[j]);
        }

        fprintf(pFile, "Total : %d\n", students[i].total);
        fprintf(pFile, "Average : %.2f\n", students[i].average);
        fprintf(pFile, "Grade : %c\n", students[i].grade);
        fprintf(pFile, "\n\n");
    }

    //CLOSE FILE
    fclose(pFile);
}

void readStudents(){
    //OPEN FILE
    FILE *pFile = fopen("students.txt", "r");
    char buffer[1024] = {0};

    if(pFile == NULL){
        printf("Cannot Open File!\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), pFile) != NULL){
        printf("%s", buffer);
    }

    //CLOSE FILE
    fclose(pFile);
}