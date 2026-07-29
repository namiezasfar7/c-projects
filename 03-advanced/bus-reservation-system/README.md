# 🚌 Bus Reservation System

A simple C-based Bus Reservation System that manages passenger seat bookings, cancellations, passenger searches, and reservation records. The program utilizes **dynamic memory allocation**, **structures**, and **file handling** to simulate a basic bus reservation management system.

---

## 📋 Features

- Accepts a user-defined passenger capacity
- Stores passenger information using **structures**
- Books seats while preventing duplicate seat reservations
- Cancels booked seats
- Searches passengers using their NIC number
- Displays all passenger reservations
- Saves reservation records to a text file
- Reads and displays saved reservation records

---

## 🛠️ Technologies Used

- C Programming
- Dynamic Memory Allocation (`malloc`)
- Structures (`struct`)
- Typedef
- Functions
- Loops & Conditional Statements
- String Handling (`string.h`)
- File Handling (`fopen`, `fprintf`, `fgets`)

---

## 📂 Project Structure

```text
Bus-Reservation-System/
│── main.c
│── bus.txt          (Generated after execution)
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
2. Enter the maximum passenger count.
3. Choose an option from the main menu:
   - Book Seat
   - Cancel Seat
   - Search Passenger
   - View Passengers
   - Save to File
   - Load File
   - Exit
4. The program will:
   - Manage seat reservations
   - Store passenger information
   - Save reservation records to **bus.txt**
   - Read and display saved reservation records

---

# 📸 Sample Output

### Scenario 1 - Book a Seat

```text
**********************
BUS RESERVATION SYSTEM
**********************

Enter Passenger Count : 3

1. Book Seat
2. Cancel Seat
3. Search Passenger
4. View Passengers
5. Save to File
6. Load File
7. Exit

Enter Choice : 1

*************************
BOOK SEAT
*************************
Enter Seat Number : 5
Enter Passenger Name : John Silva
Enter NIC Number : 200112345678
Enter Route Number : 102

Seat Booked Successfully!
```

---

### Scenario 2 - Duplicate Seat

```text
*************************
BOOK SEAT
*************************
Enter Seat Number : 5

Seat Already Booked!
```

---

### Scenario 3 - Search Passenger

```text
Enter NIC Number : 200112345678

Passenger Found
Passenger Name  : John Silva
Passenger NIC   : 200112345678
Seat Number     : 5
Route Number    : 102
Booked          : Y
```

---

### Scenario 4 - Cancel Seat

```text
Enter Seat Number : 5

Seat Cancelled Successfully!
```

---

### Scenario 5 - Save to File

```text
Saved Successfully!
```

---

### Scenario 6 - Load File

```text
**********************
BUS RESERVATION SYSTEM
**********************

Passenger 1
Passenger Name  : John Silva
Passenger NIC   : 200112345678
Seat Number     : 5
Route Number    : 102
Booked          : Y
```

---

### Scenario 7 - Invalid Passenger Count

```text
Enter Passenger Count : 0

Invalid Count!
```

---

### Scenario 8 - Memory Allocation Failure

```text
Memory Allocation Failed!
```

---

## 📄 Generated File (bus.txt)

```text
**********************
BUS RESERVATION SYSTEM
**********************

Passenger 1
Passenger Name  : John Silva
Passenger NIC   : 200112345678
Seat Number     : 5
Route Number    : 102
Booked          : Y
```

---

## 🎯 Learning Objectives

This project demonstrates:

- Dynamic Memory Allocation
- Structures and Typedef
- Modular Programming using Functions
- Arrays of Structures
- String Manipulation
- Searching Algorithms
- File Input/Output
- User Input Validation
- Reservation Management Logic
- Console Application Development

---

## 👤 Author

**Namiez Asfar**

GitHub: **https://github.com/namiezasfar7**