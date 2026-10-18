# Banking Management System in C

A console-based Banking Management System developed in C as a Data Structures and Algorithms (DSA) mini project. This project simulates basic banking operations using **Linked Lists, Stack, Structures, and Dynamic Memory Allocation**.

## 📌 Project Overview

The Banking Management System allows users to create and manage bank accounts, perform financial transactions, and view transaction history through a simple menu-driven interface.

The primary objective of this project is to demonstrate the practical implementation of Data Structures and Algorithms in C programming.

## ✨ Features

- **Create Account:** Create a new savings or current account with an automatically generated account number.
- **Display All Accounts:** View the details of all existing accounts.
- **Search Account:** Search for an account using its account number.
- **Close Account:** Close an account when its remaining balance is zero.
- **Deposit Money:** Deposit money into an existing account.
- **Withdraw Money:** Withdraw money with balance validation.
- **Transfer Money:** Transfer money between two different accounts.
- **Transaction History:** View recorded deposits, withdrawals, and transfers.
- **Input Validation:** Handle invalid inputs, account numbers, and transaction amounts.
- **Dynamic Memory Management:** Allocate memory dynamically and free allocated memory when the program exits.

## 🛠️ Technologies Used

- **Programming Language:** C
- **Data Structures:** Singly Linked List and Stack
- **Concepts:** Structures, Pointers, Dynamic Memory Allocation, Functions, Conditional Statements, Loops, and Switch-Case
- **Header Files:** `stdio.h`, `stdlib.h`, `string.h`
- **Compiler:** GCC

## 🧠 Data Structures Implemented

### 1. Singly Linked List

A linked list is used to manage bank account records dynamically. Each account node stores the account number, account holder's name, account type, balance, and a pointer to the next account.

### 2. Stack

A stack is used to maintain transaction records. New transactions are inserted at the top, so the most recent transaction is displayed first.

### 3. Structures

C structures are used to organize account information and transaction details into logical records.

## 📂 Project Structure

```text
DSA_Mini_Project/
│
├── Banking_Management_Syatem.c
└── README.md
```

## ⚙️ Installation and Setup

### Prerequisites

- GCC compiler installed on your system
- A terminal or command prompt
- Git (optional, for cloning the repository)

### Step 1: Clone the Repository

```bash
git clone https://github.com/Annix07/DSA_Mini_Project.git
```

### Step 2: Open the Project Directory

```bash
cd DSA_Mini_Project
```

### Step 3: Compile the Program

```bash
gcc Banking_Management_Syatem.c -o banking
```

### Step 4: Run the Program

**Windows:**

```bash
banking.exe
```

**Linux / macOS:**

```bash
./banking
```

## 📋 Main Menu

When the program starts, the following menu is displayed:

```text
====================================
      BANKING MANAGEMENT SYSTEM
====================================
1. Create Account
2. Display All Accounts
3. Search Account
4. Close Account
5. Deposit Money
6. Withdraw Money
7. Transfer Money
8. Transaction History
0. Exit
====================================
Enter choice:
```

Enter the corresponding option number to perform an operation. Select `0` to exit the application.

## 🔄 How It Works

1. The program initializes the account and transaction pointers.
2. The main banking menu is displayed.
3. The user selects an operation.
4. The program validates the inputs and performs the selected operation.
5. Account balances and transaction records are updated as required.
6. The menu is displayed again until the user chooses to exit.
7. Dynamically allocated account and transaction memory is released before termination.

## 🎯 Learning Objectives

- Understand the implementation of linked lists in C.
- Apply stack operations to maintain transaction history.
- Practice structures and pointers.
- Use dynamic memory allocation with `malloc()` and `free()`.
- Implement searching and record management.
- Apply validation and conditional logic to banking operations.
- Understand how data structures solve practical programming problems.

## ⚠️ Limitations

- Account and transaction data are stored in memory and are not persisted after the program terminates.
- The application is intended for educational purposes and is not a production-ready banking system.
- It does not implement authentication, database integration, or real banking services.

## 👨‍💻 Author

**Anirban Sahoo**

B.Tech | Computer Science Engineering (Data Science)

GitHub: [@Annix07](https://github.com/Annix07)

## 📄 License

This project is intended for educational and academic purposes. Add a formal open-source license if you wish to specify permissions for reuse and redistribution.
