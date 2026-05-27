#include <stdio.h>

int main()
{
    //DECLARE VARIABLES
    float celsius = 0.0f, farenheit = 0.0f;
    int choice = 0;
    
    printf("--TEMPERATURE CONVERTER--");
    printf("\nChoose Your Converter");
    printf("\n01 - Celsius to Farenheit");
    printf("\n02 - Farenheit to Celcius\n");
    
    printf("\nWhats Your choice? [01 or 02] : ");
    scanf("%d", &choice);
    
    //CONVERTER
    switch(choice)
    {
        //CELCIUS TO FARENHEIT
        case 01:
            printf("Enter Celsius Value : ");
            scanf("%f", &celsius);
            farenheit = (celsius * 0.09 / 0.05) + 32;
            printf("\n%.2f Celsius is %.2f Farenheit", celsius, farenheit);
            break;
            
        //FARENHEIT TO CELCIUS
        case 02:
            printf("Enter Farenheit Value : ");
            scanf("%f", &farenheit);
            celsius = (farenheit - 32) * 0.05 / 0.09;
            printf("\n%.2f Farenheit is %.2f Celsius", farenheit, celsius);
            break;
            
        //INVALID INPUT
        default:
            printf("Invalid Choice");
    }

    return 0;
}