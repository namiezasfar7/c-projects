#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DECLARE STRUCT
struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

//FUNCTION PROTOTYPES
void addProduct(struct Product products[], int index);

void sellProduct(struct Product products[], int count);

void restockProduct(struct Product products[], int count);

void viewProducts(struct Product products[], int count);

void saveFile(struct Product products[], int count);

//MAIN FUNCTION
int main(){
    //DECLARE VARIABLES
    int size = 0, choice = 0, count = 0;

    //ASK USER FOR SIZE
    printf("Enter Number of Products : ");
    scanf("%d", &size);

    //CHECK VALIDITY
    if(size <= 0){
        printf("Invalid Number of Products!\n");
        return 1;
    }

    //CREATE ARRAY
    struct Product *products = malloc(size * sizeof(struct Product));

    //RETURN ERROR IF MEMORY ALLOCATION FAILED
    if(products == NULL){
        printf("\nMemory Allocation Failed!");
        return 1;
    }

    printf("\n====INVENTORY SYSTEM====\n");

    //LOOP UNTIL CONDITION IS TRUE
    do{
        //PRINT MENU SCREEN
        printf("\n1. Add Product\n");
        printf("2. Sell Product\n");
        printf("3. Restock Product\n");
        printf("4. View Products\n");
        printf("5. Save File\n");
        printf("6. Exit\n");

        //GET USER INPUT
        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                //CHECK AVAILABILITY
                if(count >= size){
                    printf("Inventory Full!\n");
                }
                else{
                    //SEND TO FUNCTION
                    addProduct(products, count);

                    //ADD COUNT
                    count ++;
                }
                
                break;

            case 2:
                //SEND TO FUNCTION
                sellProduct(products, count);

                break;

            case 3:
                //SEND TO FUNCTION
                restockProduct(products, count);

                break;

            case 4:
                //SEND TO FUNCTION
                viewProducts(products, count);

                break;

            case 5:
                //SEND TO FUNCTION
                saveFile(products, count);

                break;

            case 6:
                printf("Thank You For Using This System!\n");
                break;

            default:
                printf("Invalid Choice! Try Again!\n");
        }

    }while(choice != 6);

    //FREE MEMORY
    free(products);
    products = NULL;

    return 0;
}

//OTHER FUNCTIONS
void addProduct(struct Product products[], int index){  
    //GET USER INPUT
    printf("\nEnter Product ID : ");
    scanf("%d", &products[index].id);
    getchar();

    for(int i = 0; i < index; i++) {
        if(products[i].id == products[index].id) {
            printf("Product ID already exists!\n");
            return;
        }
    }

    printf("Enter Product Name : ");
    fgets(products[index].name, sizeof(products[index].name), stdin);
    products[index].name[strcspn(products[index].name, "\n")] = '\0';

    printf("Enter Quantity : ");
    scanf("%d", &products[index].quantity);

    printf("Enter Price : ");
    scanf("%f", &products[index].price);
}

void sellProduct(struct Product products[], int count){
    //DECLARE VARIABLES
    int id = 0, quantity = 0, found = 0;

    //GET USER INPUT
    printf("\nEnter Product ID : ");
    scanf("%d", &id);

    printf("Enter Quantity : ");
    scanf("%d", &quantity);

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < count; i++){
        //CHECK IN ARRAY
        if(id == products[i].id){
            //CHANGE FOUND
            found = 1;

            //CHECK QUANTITY
            if(quantity > products[i].quantity){
                printf("Insufficient Stocks!\n");
            }
            else{
                //SUBTRACT STOCKS
                products[i].quantity -= quantity;

                //GIVE CONFIRMATION MESSAGE
                printf("\nStocks Sold Successfully!\n");
                printf("New Stocks : %d\n", products[i].quantity);

                break;
            }
        }
    }

    //PRINT FOR FOUND
    if(found == 0){
        printf("Product Not Found!\n");
    }
}

void restockProduct(struct Product products[], int count){
    //DECLARE VARIABLES
    int id = 0, quantity = 0, found = 0;

    //GET USER INPUT
    printf("\nEnter Product ID : ");
    scanf("%d", &id);

    printf("Enter Quantity : ");
    scanf("%d", &quantity);

    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < count; i++){
        //CHECK IN ARRAY
        if(id == products[i].id){
            //CHANGE FOUND
            found = 1;

            //ADD STOCKS
            products[i].quantity += quantity;

            //GIVE CONFIRMATION MESSAGE
            printf("\nStocks Added Successfully!\n");
            printf("New Stocks : %d\n", products[i].quantity);

            break;
        }
    }

    //PRINT FOR FOUND
    if(found == 0){
        printf("Product Not Found!\n");
    }
}

void viewProducts(struct Product products[], int count){
    //LOOP UNTIL CONDITION IS TRUE
    for(int i = 0; i < count; i++){
        //PRINT OUTPUT
        printf("\nProduct ID : %d\n", products[i].id);
        printf("Product Name : %s\n", products[i].name);
        printf("Quantity : %d\n", products[i].quantity);
        printf("Price : %.2f\n", products[i].price);
    }
}

void saveFile(struct Product products[], int count){
    //OPEN FILE
    FILE *pFile = fopen("products.txt", "w");

    if(pFile == NULL){
        printf("Cannot Create File!\n");
        return;
    }

    fprintf(pFile, "====INVENTORY SYSTEM====\n\n");

    //SAVE TO FILE
    for(int i = 0; i < count; i++){
        fprintf(pFile, "-----------------------------");
        fprintf(pFile, "Product ID : %d\n", products[i].id);
        fprintf(pFile, "Product Name : %s\n", products[i].name);
        fprintf(pFile, "Quantity : %d\n", products[i].quantity);
        fprintf(pFile, "Price : %.2f\n", products[i].price);
        fprintf(pFile, "-----------------------------");
        fprintf(pFile, "\n\n");
    }

    //CLOSE FILE
    fclose(pFile);

    //CONFIRMATION MESSAGE
    printf("Saved successfully!\n");
}