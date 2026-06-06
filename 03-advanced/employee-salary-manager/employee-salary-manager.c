#include <stdio.h>
#include <stdlib.h>

int main(){

    //DECLARE VARIABLES
    int empCount = 0;
    float totalSalary = 0.0f, highestSalary = 0.0f, lowestSalary = 0.0f, avgSalary = 0.0f;

    //GET USER INPUT
    printf("How many employees? : ");
    scanf("%d", &empCount);

    //CHECK VALIDITY
    if (empCount <= 0) {
        printf("Invalid number of employees.\n");
        return 1;
    }

    //ALLOCATE MEMORY FOR EMPLOYEE COUNT
    float *salaries = malloc(empCount * sizeof(float));

    //DECLARE ARRAY FOR NEW SALARIES
    float *newSalaries = malloc(empCount * sizeof(float));

    //RETURN ERROR IF MEMORY ALLOCATION FAILED
    if(salaries == NULL || newSalaries == NULL){
        printf("\nMemory Allocation Failed!");
        return 1;
    }

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < empCount; i ++){

        //GET USER INPUT
        printf("Enter salary of employee %d : Rs. ", i + 1);
        scanf("%f", &salaries[i]);

        //ADD TOTAL
        totalSalary += salaries[i];

        //SET DEFAULT HIGHEST AND LOWEST
        if(i == 0){
            highestSalary = salaries[i];
            lowestSalary = salaries[i];
        }

        //GET LOWEST AND HIGHEST
        if(salaries[i] < lowestSalary){
            lowestSalary = salaries[i];
        }

        if(salaries[i] > highestSalary){
            highestSalary = salaries[i];
        }

        //GIVE 10% RAISE
        newSalaries[i] = salaries[i] + (salaries[i] * 0.10);
    }

    //AVERAGE SALARIES
    avgSalary = (float) totalSalary / empCount;

    //PRINT OUTPUT
    printf("\n====SUMMARY====\n");
    printf("\nHighest Salary : Rs. %.2f", highestSalary);
    printf("\nLowest Salary : Rs. %.2f", lowestSalary);
    printf("\nAverage Salary : Rs. %.2f", avgSalary);
    printf("\nTotal Salary : Rs. %.2f\n", totalSalary);
    printf("\nNew Salaries After 10 Percent Bonus : ");
    for(int i = 0; i < empCount; i ++){
        printf("\nEmployee %d : Rs. %.2f", i + 1, newSalaries[i]);
    }

    //FREE MEMORY
    free(salaries);
    free(newSalaries);
    salaries = NULL;
    newSalaries = NULL;

    return 0;
}