# 👔 Employee Payroll System

A simple C-based Employee Payroll System that manages employee salary information, calculates payroll statistics, and generates a payroll report in a text file.

---

## 📋 Features

- Accepts user-defined employee count
- Stores employee information using **structures**
- Calculates each employee's **net salary**
- Finds the **highest** and **lowest** net salary
- Calculates the **average** net salary
- Saves the payroll report to a text file
- Reads and displays the saved report

---

## 🛠️ Technologies Used

- C Programming
- Dynamic Memory Allocation (`malloc`)
- Structures (`struct`)
- Typedef
- Functions
- Loops & Conditional Statements
- String Handling
- File Handling (`fopen`, `fprintf`, `fgets`)

---

## 📂 Project Structure

```text
Employee-Payroll-System/
│── main.c
│── employees.txt      (Generated after execution)
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
2. Enter the number of employees.
3. Enter each employee's:
   - Employee ID
   - Employee Name
   - Basic Salary
   - Allowance
   - Deduction
4. The program will:
   - Calculate net salaries
   - Display the payroll report
   - Save the report to **employees.txt**
   - Read and display the saved report

---

# 📸 Sample Output (Program)

```text
========================
SCENARIO 1 - VALID INPUT
========================

***********************
EMPLOYEE PAYROLL SYSTEM
***********************
Enter Employee Count : 3

***********************
Enter Employee ID   : EMP001
Enter Employee Name : John Silva
Enter Basic Salary  : Rs. 60000
Enter Allowance     : Rs. 8000
Enter Deduction     : Rs. 5000

***********************
Enter Employee ID   : EMP002
Enter Employee Name : Nimal Perera
Enter Basic Salary  : Rs. 45000
Enter Allowance     : Rs. 6000
Enter Deduction     : Rs. 3000

***********************
Enter Employee ID   : EMP003
Enter Employee Name : Kasun Fernando
Enter Basic Salary  : Rs. 75000
Enter Allowance     : Rs. 12000
Enter Deduction     : Rs. 7000

***********************
EMPLOYEE PAYROLL SYSTEM
***********************
Employee 1
    Employee ID     : EMP001
    Employee Name   : John Silva
    Basic Salary    : Rs. 60000.00
    Allowance       : Rs. 8000.00
    Deduction       : Rs. 5000.00
    Net Salary      : Rs. 63000.00
***********************
Employee 2
    Employee ID     : EMP002
    Employee Name   : Nimal Perera
    Basic Salary    : Rs. 45000.00
    Allowance       : Rs. 6000.00
    Deduction       : Rs. 3000.00
    Net Salary      : Rs. 48000.00
***********************
Employee 3
    Employee ID     : EMP003
    Employee Name   : Kasun Fernando
    Basic Salary    : Rs. 75000.00
    Allowance       : Rs. 12000.00
    Deduction       : Rs. 7000.00
    Net Salary      : Rs. 80000.00
***********************
Average Salary : Rs. 63666.67
***********************
HIGHEST SALARY
Employee ID    : EMP003
Salary         : Rs. 80000.00
***********************
LOWEST SALARY
Employee ID    : EMP002
Salary         : Rs. 48000.00
***********************

=========================
SCENARIO 2 - INVALID COUNT
=========================

***********************
EMPLOYEE PAYROLL SYSTEM
***********************
Enter Employee Count : 0
Invalid Employee Count!

==============================
SCENARIO 3 - NEGATIVE EMPLOYEES
==============================

***********************
EMPLOYEE PAYROLL SYSTEM
***********************
Enter Employee Count : -5
Invalid Employee Count!

==================================
SCENARIO 4 - MEMORY ALLOCATION FAIL
==================================

***********************
EMPLOYEE PAYROLL SYSTEM
***********************
Enter Employee Count : 999999999
Memory Allocation Failed!
```

---

# 📄 Generated File (employees.txt)

```text
***********************
EMPLOYEE PAYROLL SYSTEM
***********************
Employee 1
    Employee ID     : EMP001
    Employee Name   : John Silva
    Basic Salary    : Rs. 60000.00
    Allowance       : Rs. 8000.00
    Deduction       : Rs. 5000.00
    Net Salary      : Rs. 63000.00
***********************
Employee 2
    Employee ID     : EMP002
    Employee Name   : Nimal Perera
    Basic Salary    : Rs. 45000.00
    Allowance       : Rs. 6000.00
    Deduction       : Rs. 3000.00
    Net Salary      : Rs. 48000.00
***********************
Employee 3
    Employee ID     : EMP003
    Employee Name   : Kasun Fernando
    Basic Salary    : Rs. 75000.00
    Allowance       : Rs. 12000.00
    Deduction       : Rs. 7000.00
    Net Salary      : Rs. 80000.00
***********************
Average Salary : Rs. 63666.67
***********************
HIGHEST SALARY
Employee ID    : EMP003
Salary         : Rs. 80000.00
***********************
LOWEST SALARY
Employee ID    : EMP002
Salary         : Rs. 48000.00
***********************
```

---

## 🎯 Learning Objectives

This project demonstrates:

- Dynamic memory allocation
- Structures and typedef
- Modular programming using functions
- File input/output
- Arrays of structures
- Basic payroll calculations
- String manipulation

---

## 👤 Author

**Namiez Asfar**

GitHub: **https://github.com/namiezasfar7**