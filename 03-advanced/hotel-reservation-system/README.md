# Hotel Reservation System 🏨

A hotel reservation system that manages rooms

## 📋 Features
- Gets user input for room numbers, customer names, etc
- Updates room status
- Calculates Bill
- Saves to file

## 🛠️ How to Run
```bash
gcc hotel-reservation-system.c -o hotel-reservation-system
./hotel-reservation-system
```

## 📖 How to Use
1. Run the program
2. View menu and select choice
3. follow menu options

## 💡 Concepts Used
- Loops and conditions
- Multiple libraries
- Functions
- Switch case
- Arrays
- File handling
- Structs

## 📸 Sample Output - Program
=================HOTEL RESERVATION SYSTEM=================

1. Reserve Room---------------------------------------------
2. Checkout-------------------------------------------------
3. View Rooms-----------------------------------------------
4. Save File------------------------------------------------
5. Load File------------------------------------------------
6. Exit-----------------------------------------------------

Enter Choice : 1

========================RESERVE ROOM========================

Enter Room Number   : 101
Enter Customer Name : John Smith

Enter Days Staying  : 3
Room Reserved Successfully!

1. Reserve Room---------------------------------------------
2. Checkout-------------------------------------------------
3. View Rooms-----------------------------------------------
4. Save File------------------------------------------------
5. Load File------------------------------------------------
6. Exit-----------------------------------------------------

Enter Choice : 1

========================RESERVE ROOM========================

Enter Room Number   : 102
Enter Customer Name : Alice Brown

Enter Days Staying  : 2
Room Reserved Successfully!

1. Reserve Room---------------------------------------------
2. Checkout-------------------------------------------------
3. View Rooms-----------------------------------------------
4. Save File------------------------------------------------
5. Load File------------------------------------------------
6. Exit-----------------------------------------------------

Enter Choice : 3

=========================ROOM STATUS=========================


Room Number     : 101
Customer Name   : John Smith
Days Staying    : 3
Is Occupied     : Y

Room Number     : 102
Customer Name   : Alice Brown
Days Staying    : 2
Is Occupied     : Y

1. Reserve Room---------------------------------------------
2. Checkout-------------------------------------------------
3. View Rooms-----------------------------------------------
4. Save File------------------------------------------------
5. Load File------------------------------------------------
6. Exit-----------------------------------------------------

Enter Choice : 2

===========================CHECKOUT==========================

Enter Room Number   : 101
Final Bill Amount : Rs. 60000

1. Reserve Room---------------------------------------------
2. Checkout-------------------------------------------------
3. View Rooms-----------------------------------------------
4. Save File------------------------------------------------
5. Load File------------------------------------------------
6. Exit-----------------------------------------------------

Enter Choice : 3

=========================ROOM STATUS=========================


Room Number     : 101
Customer Name   : John Smith
Days Staying    : 3
Is Occupied     : N

Room Number     : 102
Customer Name   : Alice Brown
Days Staying    : 2
Is Occupied     : Y

1. Reserve Room---------------------------------------------
2. Checkout-------------------------------------------------
3. View Rooms-----------------------------------------------
4. Save File------------------------------------------------
5. Load File------------------------------------------------
6. Exit-----------------------------------------------------

Enter Choice : 4
Saved successfully!

1. Reserve Room---------------------------------------------
2. Checkout-------------------------------------------------
3. View Rooms-----------------------------------------------
4. Save File------------------------------------------------
5. Load File------------------------------------------------
6. Exit-----------------------------------------------------

Enter Choice : 5
=================HOTEL RESERVATION SYSTEM=================

Room Number     : 101
Customer Name   : John Smith
Days Staying    : 3
Is Occupied     : N

Final Bill      : 60000
-------------------------------------------------------------

Room Number     : 102
Customer Name   : Alice Brown
Days Staying    : 2
Is Occupied     : Y

Final Bill      : 0
-------------------------------------------------------------

1. Reserve Room---------------------------------------------
2. Checkout-------------------------------------------------
3. View Rooms-----------------------------------------------
4. Save File------------------------------------------------
5. Load File------------------------------------------------
6. Exit-----------------------------------------------------

Enter Choice : 6

Thank You For Using This System!

## 📸 Sample Output - File
=================HOTEL RESERVATION SYSTEM=================

Room Number     : 101
Customer Name   : John Smith
Days Staying    : 3
Is Occupied     : N

Final Bill      : 60000
-------------------------------------------------------------

Room Number     : 102
Customer Name   : Alice Brown
Days Staying    : 2
Is Occupied     : Y

Final Bill      : 0
-------------------------------------------------------------

## 👤 Author
Namiez Asfar
[GitHub](https://github.com/namiezasfar7)