# ✈️ Airline Reservation System

A simple C-based Airline Reservation System that allows users to book and cancel seats, search for passengers, view reservations, and save reservation data to a text file. The project demonstrates the use of structures, dynamic memory allocation, modular programming, and file handling in C.

---

## 📋 Features

- User-defined seat capacity
- Book airline seats
- Cancel booked seats
- Search passengers using passport number
- View all seat reservations
- Save reservation data to a text file
- Load and display saved reservation data
- Uses dynamic memory allocation for passenger records

---

## 🛠️ Technologies Used

- C Programming
- Structures (`struct`)
- Typedef
- Dynamic Memory Allocation (`malloc`)
- Functions
- Arrays of Structures
- String Handling (`string.h`)
- File Handling (`fopen`, `fprintf`, `fgets`)
- Boolean Data Type (`stdbool.h`)

---

## 📂 Project Structure

```text
airline-reservation-system/
│── main.c
│── airline.txt      (Generated after execution)
└── README.md
```

---

## ▶️ How to Compile and Run

### Compile

```bash
gcc main.c -o main
```

### Run

```bash
./main
```

---

## 📖 Usage

1. Run the program.
2. Enter the total number of seats available.
3. Select an option from the menu:
   - Book Seat
   - Cancel Seat
   - Search Passenger
   - View Seats
   - Save File
   - Load File
   - Exit
4. The program will manage reservations based on your selection.
5. Reservation details can be saved to **airline.txt** and loaded later for viewing.

---

# 📸 Sample Output

### Scenario 1 - Booking a Seat

```text
***********************
AIRLINE RESERVATION SYSTEM
***********************
Enter Seat Count : 5

1. Book Seat
2. Cancel Seat
3. Search Passenger
4. View Seats
5. Save File
6. Load File
7. Exit

Enter Choice : 1

*************************
BOOK SEAT
*************************
Enter Seat Number : 1
Enter Passport Number : N1234567
Enter Passenger Name : John Silva
Enter Destination : Singapore

Seat Booked Successfully!
```

---

### Scenario 2 - Search Passenger

```text
Enter Passport Number : N1234567

Passenger Found
Passport Number : N1234567
Passenger Name  : John Silva
Seat Number     : 1
Destination     : Singapore
Booked          : Y
```

---

### Scenario 3 - Cancel Seat

```text
Enter Seat Number : 1

Seat Cancelled Successfully!
```

---

### Scenario 4 - View Seats

```text
*********** SEATS ***********

Seat Number      : 2
Passport Number  : N9876543
Passenger Name   : Jane Perera
Destination      : Dubai
Booked           : Y
```

---

### Scenario 5 - Save File

```text
Saved Successfully!
```

---

### Scenario 6 - Load File

```text
******************************
AIRLINE RESERVATION SYSTEM
******************************

Passenger 1
Passport Number : N1234567
Passenger Name  : John Silva
Seat Number     : 1
Destination     : Singapore
Booked          : Y
```

---

## 📄 Generated File (airline.txt)

```text
******************************
AIRLINE RESERVATION SYSTEM
******************************

Passenger 1
Passport Number : N1234567
Passenger Name  : John Silva
Seat Number     : 1
Destination     : Singapore
Booked          : Y

Passenger 2
Passport Number : N9876543
Passenger Name  : Jane Perera
Seat Number     : 2
Destination     : Dubai
Booked          : Y
```

---

## 🎯 Learning Objectives

This project demonstrates:

- Dynamic memory allocation
- Structures and typedef
- Arrays of structures
- Modular programming using functions
- String manipulation
- Searching techniques
- File input/output
- Menu-driven applications
- Data management using structures
- Basic airline reservation logic

---

## 👤 Author

**Namiez Asfar**

GitHub: **https://github.com/namiezasfar7**