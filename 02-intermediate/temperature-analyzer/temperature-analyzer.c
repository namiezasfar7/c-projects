#include <stdio.h>

//FUNCTION PROTOTYPES
void inputTemperature(int temperatures[], int size);

void calculateTemperature(int temperatures[],
                          int size,
                          int *highestTemp,
                          int *lowestTemp,
                          float *avgTemp
);

void saveToFile(int temperatures[],
                int size,
                int highestTemp,
                int lowestTemp,
                float avgTemp
);

//MAIN FUNCTION
int main(){
    //DECLARE ARRAY
    int temperatures[7] = {0};
    int size = 7;

    //DECLARE VARIABLES
    int highestTemp = 0, lowestTemp = 0;
    float avgTemp = 0.0f;

    //GET TEMPERATURES
    inputTemperature(temperatures, size);

    //DO CALCULATIONS
    calculateTemperature(temperatures, size, &highestTemp, &lowestTemp, &avgTemp);

    //PRINT OUTPUT
    printf("\n====TEMPERATURE REPORT====\n\n");

    for(int i = 0; i < size; i ++){
        printf("Day %d : %d°C\n", i + 1; temperatures[i]);
    }

    printf("\nHighest Temperature : %d°C", highestTemp);
    printf("\nLowest Temperature : %d°C", lowestTemp);
    printf("\nAverage Temparature : %.2f°C", avgTemp);

    //SAVE FILE
    saveToFile(temperatures, size, highestTemp, lowestTemp, avgTemp);

    return 0;
}

//OTHER FUNCTIONS
void inputTemperature(int temperatures[], int size){
    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < size; i ++){
        //GET USER INPUT
        printf("Enter Temperature of Day %d : ", i + 1);
        scanf("%d", &temperatures[i]);
    }
}

void calculateTemperature(int temperatures[],
                          int size,
                          int *highestTemp,
                          int *lowestTemp,
                          float *avgTemp
){
    //DECLARE VARIABLE
    int totalTemp = 0;

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < size; i ++){
        //CALCULATE TOTAL
        totalTemp += temperatures[i];

        //SET DEFAULT HIGHEST AND LOWEST TEMPERATURE
        if(i == 0){
            *highestTemp = temperatures[i];
            *lowestTemp = temperatures[i];
        }

        //FIND LOWEST TEMPERATURE
        if(temperatures[i] < *lowestTemp){
            *lowestTemp = temperatures[i];
        }

        //FIND HIGHEST TEMPERATURE
        if(temperatures[i] > *highestTemp){
            *highestTemp = temperatures[i];
        }
    }

    //CALCULATE AVERAGE
    *avgTemp = (float) totalTemp / size;
}

void saveToFile(int temperatures[],
                int size,
                int highestTemp,
                int lowestTemp,
                float avgTemp
){
    //OPEN FILE
    FILE *pFile = fopen("temperature.txt", "w");

    if(pFile == NULL){
        printf("\nCannot Open File!");
        return;
    }

    //WRITE FILE
    fprintf(pFile, "====TEMPERATURE REPORT====\n\n");

    for(int i = 0; i < size; i ++){
        fprintf(pFile, "Temperature of Day %d : %d°C\n", i + 1, temperatures[i]);
    }

    fprintf(pFile, "\nHighest Temperature : %d°C", highestTemp);
    fprintf(pFile, "\nLowest Temperature : %d°C", lowestTemp);
    fprintf(pFile, "\nAverage Temparature : %.2f°C", avgTemp);

    //CLOSE FILE
    fclose(pFile);

    //CONFIRMATION MESSAGE
    printf("\nReport saved successfully!\n");
}