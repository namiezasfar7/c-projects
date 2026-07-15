#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DECLARE STRUCT
typedef struct {
    char id[20];
    char name[50];
    float basicSalary;
    float allowance;
    float deduction;
    float netSalary;
} Employee;

//FUNCTION PROTOTYPES
void inputEmployees(Employee employees[], int employeeCount);

void calculateSalary(Employee employees[], int employeeCount);

void findHighLow(Employee employees[],
                 int employeeCount,
                 float *highestAmt,
                 float *lowestAmt,
                 char highestId[],
                 char lowestId[]
);

float calculateAverage(Employee employees[], int employeeCount);

void saveReport(Employee employees[],
                int employeeCount,
                float average,
                float highestAmt,
                float lowestAmt,
                char highestId[],
                char lowestId[]
);

void readReport();

//MAIN FUNCTION
int main(){

    //DECLARE VARIABLES
    int employeeCount = 0;
    int choice = 0;

    float average = 0.0f;

    float highestSalary = 0.0f;
    float lowestSalary = 0.0f;

    char highestId[20] = "";
    char lowestId[20] = "";

    //GET USER INPUT FOR EMPLOYEE COUNT
    printf("***********************\n");
    printf("EMPLOYEE PAYROLL SYSTEM\n");
    printf("***********************\n");

    printf("Enter Employee Count : ");
    scanf("%d", &employeeCount);

    if(employeeCount <= 0){
        printf("Invalid Employee Count!\n");
        return 1;
    }

    //CREATE ARRAY
    Employee *employees = malloc(employeeCount * sizeof(Employee));

    //RETURN ERROR IF MEMORY ALLOCATION FAILED
    if(employees == NULL){
        printf("Memory Allocation Failed!\n");
        return 1;
    }

    //GET USER INPUT
    inputEmployees(employees, employeeCount);

    //CALCULATE SALARY
    calculateSalary(employees, employeeCount);

    //FIND HIGHEST & LOWEST SALARY
    findHighLow(employees, employeeCount, &highestSalary, &lowestSalary, highestId, lowestId);

    //FIND AVERAGE
    average = calculateAverage(employees, employeeCount);

    //SAVE TO FILE
    saveReport(employees, employeeCount, average, highestSalary, lowestSalary, highestId, lowestId);

    //READ FROM FILE
    readReport();

    //CLOSE & CLEAN ARRAY
    free(employees);
    employees = NULL;

    return 0;
}

//OTHER FUNCTIONS
//GET USER INPUT
void inputEmployees(Employee employees[], int employeeCount){

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < employeeCount; i ++){

        printf("***********************\n");
        printf("Enter Employee ID   : ");
        scanf("%s", employees[i].id);

        getchar();

        printf("Enter Employee Name : ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';

        printf("Enter Basic Salary  : Rs. ");
        scanf("%f", &employees[i].basicSalary);

        printf("Enter Allowance     : Rs. ");
        scanf("%f", &employees[i].allowance);

        printf("Enter Deduction     : Rs. ");
        scanf("%f", &employees[i].deduction);
    }
}

//CALCULATE SALARY
void calculateSalary(Employee employees[], int employeeCount){
    
    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < employeeCount; i ++){

        //CALCULATE NET SALARY
        employees[i].netSalary = (employees[i].basicSalary + employees[i].allowance) - employees[i].deduction;
    }
}

//FIND HIGHEST & LOWEST SALARY
void findHighLow(Employee employees[],
                 int employeeCount,
                 float *highestAmt,
                 float *lowestAmt,
                 char highestId[],
                 char lowestId[]
){

    //SET DEFAULT HIGH AND LOW
    *highestAmt = employees[0].netSalary;
    *lowestAmt = employees[0].netSalary;

    strcpy(highestId, employees[0].id);
    strcpy(lowestId, employees[0].id);

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 1; i < employeeCount; i ++){

        //FIND HIGHEST
        if(employees[i].netSalary > *highestAmt){
            *highestAmt = employees[i].netSalary;
            
            strcpy(highestId, employees[i].id);
        }

        //FIND LOWEST
        if(employees[i].netSalary < *lowestAmt){
            *lowestAmt = employees[i].netSalary;
            
            strcpy(lowestId, employees[i].id);
        }
    }
}

//FIND AVERAGE SALARY
float calculateAverage(Employee employees[], int employeeCount){

    //DECLARE VARIABLES
    float sum = 0.0f;
    
    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < employeeCount; i ++){

        //CALCULATE SUM
        sum += employees[i].netSalary;
    }

    return (sum / employeeCount);
}

//SAVE TO FILE
void saveReport(Employee employees[],
                int employeeCount,
                float average,
                float highestAmt,
                float lowestAmt,
                char highestId[],
                char lowestId[]
){
    //OPEN FILE
    FILE *pFile = fopen("employees.txt", "w");

    if(pFile == NULL){
        printf("Couldn't Create File!\n");
        return;
    }

    //WRITE TO FILE
    fprintf(pFile, "***********************\n");
    fprintf(pFile, "EMPLOYEE PAYROLL SYSTEM\n");
    fprintf(pFile, "***********************\n");

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < employeeCount; i ++){

        fprintf(pFile, "Employee %d\n", i + 1);
        fprintf(pFile, "    Employee ID     : %s\n", employees[i].id);
        fprintf(pFile, "    Employee Name   : %s\n", employees[i].name);
        fprintf(pFile, "    Basic Salary    : Rs. %.2f\n", employees[i].basicSalary);
        fprintf(pFile, "    Allowance       : Rs. %.2f\n", employees[i].allowance);
        fprintf(pFile, "    Deduction       : Rs. %.2f\n", employees[i].deduction);
        fprintf(pFile, "    Net Salary      : Rs. %.2f\n", employees[i].netSalary);
        fprintf(pFile, "***********************\n");
    }

    fprintf(pFile, "Average Salary : Rs. %.2f\n", average);
    fprintf(pFile, "***********************\n");
    
    fprintf(pFile, "HIGHEST SALARY\n");
    fprintf(pFile, "Employee ID    : %s\n", highestId);
    fprintf(pFile, "Salary         : Rs. %.2f\n", highestAmt);
    fprintf(pFile, "***********************\n");

    fprintf(pFile, "LOWEST SALARY\n");
    fprintf(pFile, "Employee ID    : %s\n", lowestId);
    fprintf(pFile, "Salary         : Rs. %.2f\n", lowestAmt);
    fprintf(pFile, "***********************\n");

    //CLOSE FILE
    fclose(pFile);
}

//READ FROM FILE
void readReport(){
    
    //OPEN FILE
    FILE *pFile = fopen("employees.txt", "r");
    char buffer[1024] = {0};

    if(pFile == NULL){
        printf("Couldn't Open File!\n");
        return;
    }

    //READ FILE
    while(fgets(buffer, sizeof(buffer), pFile) != NULL){
        printf("%s", buffer);
    }

    //CLOSE FILE
    fclose(pFile);
}