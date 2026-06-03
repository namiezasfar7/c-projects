#include <stdio.h>
#include <string.h>

int main(){

    //DECLARE VARIABLES
    int total = 0, avg = 0, min = 0, max = 0;
    char minMonth[20] = "", maxMonth[20] = "";

    //DECLARE ARRAY
    char months[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int cases[12] = {0};

    //GET USER INPUT
    for(int i = 0; i < 12; i ++){
        printf("Enter Number of Cases for the Month of %s : ", months[i]);
        scanf("%d", &cases[i]);

        //ADD TOTAL
        total += cases[i];

        //SET DEFAULT MIN AND MAX
        if(i == 0){
            min = cases[i];
            max = cases[i];
            strcpy(minMonth, months[i]);
            strcpy(maxMonth, months[i]);
        }

        //GET MIN
        if(cases[i] < min){
            min = cases[i];
            strcpy(minMonth, months[i]);
        }

        //GET MAX
        if(cases[i] > max){
            max = cases[i];
            strcpy(maxMonth, months[i]);
        }
    }

    //GET AVERAGE
    avg = total / 12;

    //PRINT OUTPUT
    printf("\n====COVID CASES THIS YEAR====\n");
    printf("\nTotal Covid Cases this Year : %d", total);
    printf("\nAverage Number of Cases this Year : %d", avg);
    printf("\n%s had the Least Cases this Year : %d", minMonth, min);
    printf("\n%s had the Most Cases this Year : %d", maxMonth, max);
    printf("\nMonths with Cases More Than Average : ");

    for(int i = 0; i < 12; i ++){
        if(cases[i] > avg){
            printf("%s, ", months[i]);
        }
    }

    return 0;
}