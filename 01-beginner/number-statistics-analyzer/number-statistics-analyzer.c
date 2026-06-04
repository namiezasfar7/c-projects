#include <stdio.h>

int main(){

    //DECLARE VARIABLES
    int largest = 0, smallest = 0, sum = 0;
    float avg = 0;

    //DECLARE ARRAY
    int numbers[10] = {0};

    //GET USER INPUT
    for(int i = 0; i < 10; i ++){
        printf("Enter Number %d : ", i + 1);
        scanf("%d", &numbers[i]);

        //ADD SUM
        sum += numbers[i];

        //SET DEFAULT LARGEST AND SMALLEST
        if(i == 0){
            largest = numbers[i];
            smallest = numbers[i];
        }

        //GET SMALLEST
        if(numbers[i] < smallest){
            smallest = numbers[i];
        }

        //GET LARGEST
        if(numbers[i] > largest){
            largest = numbers[i];
        }
    }

    //CALCULATE AVERAGE
    avg = (float) sum / 10;

    //PRINT OUTPUT
    printf("\nLargest : %d", largest);
    printf("\nSmallest : %d", smallest);
    printf("\nSum : %d", sum);
    printf("\nAverage : %.2f", avg);

    return 0;
}