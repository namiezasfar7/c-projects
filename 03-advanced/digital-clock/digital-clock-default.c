#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

int main(){

    //DECLARE VARIABLES
    time_t rawtime = 0; // Epoch Time (Jan 1 1970)
    struct tm *pTime = NULL;
    bool isRunning = true;

    //WELCOME MESSAGE
    printf("DIGITAL CLOCK\n");

    //LOOP UNTIL CONDITION IS TRUE
    while(isRunning){

        //GET TIME
        time(&rawtime);

        //POINT TO STRUCT tm
        pTime = localtime(&rawtime);

        //PRINT TIME
        printf("\r%02d:%02d:%02d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);

        //UPDATES EVERY 1 SECOND
        sleep(1);
    }

    return 0;
}