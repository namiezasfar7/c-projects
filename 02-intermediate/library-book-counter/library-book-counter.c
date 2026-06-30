#include <stdio.h>
#include <string.h>

//DECLARE STRUCT
struct Book{
    char title[50];
    int copies;
};

//FUNCTION PROTOTYPES
void addBooks(struct Book books[], int size);

void viewBooks(struct Book books[], int size);

int findTotalCopies(struct Book books[], int size);

void saveReport(FILE *pFile, struct Book books[], int size);

//MAIN FUNCTION
int main(){
    //DECLARE ARRAY
    struct Book books[20] = {0};

    //DECLARE VARIABLES
    int choice = 0, size = 20, total = 0;

    //OPEN FILE
    FILE *pFile = fopen("books.txt", "w");

    if(pFile == NULL){
        printf("Cannot Open File!\n");
        return 1;
    }

    fprintf(pFile, "====LIBRARY BOOK COUNTER====\n");

    //LOOP UNTIL CONDITION IS TRUE
    do{
        //GET USER INPUT
        printf("\n==== LIBRARY BOOK COUNTER ====\n");
        printf("1. Add Books\n");
        printf("2. View Books\n");
        printf("3. Find Total Copies\n");
        printf("4. Save Report\n");
        printf("5. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d", &choice);
        getchar();

        if(choice == 5){
            printf("\nThank You For Using Our System!\n");
            break;
        }

        //CHECK CHOICE
        switch(choice){
            case 1:
                addBooks(books, size);
                break;

            case 2:
                viewBooks(books, size);
                break;

            case 3:
                total = findTotalCopies(books, size);
                printf("\nTotal Copies : %d\n", total);
                break;

            case 4:
                saveReport(pFile, books, size);
                printf("\nSaved to File Successfully\n");
                break;

            case 5:
                printf("\nThank You For Using Our System!\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again!\n");
                break;
        }

    }while(choice != 5);

    //CLOSE FILE
    fclose(pFile);

    return 0;
}

//OTHER FUNCTIONS
void addBooks(struct Book books[], int size){
    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < size; i++){

        printf("\nBook %d\n", i + 1);

        //GET USER INPUT
        printf("Enter Book Name : ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0';

        printf("Enter Number of Copies : ");
        scanf("%d", &books[i].copies);

        getchar();
    }
}

void viewBooks(struct Book books[], int size){
    //PRINT OUTPUT
    printf("\n===== BOOK LIST =====\n");

    for(int i = 0; i < size; i ++){
        printf("\nBook %d\n", i + 1);
        printf("Book Name : %s\n", books[i].title);
        printf("Book Copies : %d\n", books[i].copies);
    }
}

int findTotalCopies(struct Book books[], int size){
    //DECLARE VARIABLE
    int total = 0;

    //PRINT OUTPUT
    for(int i = 0; i < size; i ++){
        total += books[i].copies;
    }

    return total;
}

void saveReport(FILE *pFile, struct Book books[], int size){
    //SAVE TO FILE
    fprintf(pFile,"===== LIBRARY REPORT =====\n\n");

    for(int i = 0; i < size; i++){
        fprintf(pFile,"Book %d\n", i + 1);
        fprintf(pFile,"Title  : %s\n", books[i].title);
        fprintf(pFile,"Copies : %d\n\n", books[i].copies);

    }

    fprintf(pFile,"Total Copies : %d\n", findTotalCopies(books, size));
}