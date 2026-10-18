#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accNo;
    char name[50];
    int type;
    double balance;
    struct Account *next;
};

struct Transaction {
    int id;
    int type;
    int accNo;
    int receiver;
    double amount;
    struct Transaction *next;
};

struct Account *head = NULL;
struct Transaction *top = NULL;

int nextAccNo = 1001;
int nextTransID = 1;

struct Account *search(int accNo);
void createAccount(void);
void displayAccounts(void);
void searchAccount(void);
void closeAccount(void);
void deposit(void);
void withdraw(void);
void transfer(void);
int addTransaction(int type, int accNo, int receiver, double amount);
void transactionHistory(void);
void freeMemory(void);

struct Account *search(int accNo) {
    struct Account *temp = head;

    while (temp != NULL) {
        if (temp->accNo == accNo)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

void createAccount(void) {
    struct Account *newAccount, *temp;

    newAccount = (struct Account *)malloc(sizeof(struct Account));

    if (newAccount == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter customer name: ");
    scanf(" %49[^\n]", newAccount->name);

    printf("1. Savings Account\n");
    printf("2. Current Account\n");
    printf("Enter account type: ");

    if (scanf("%d", &newAccount->type) != 1) {
        printf("Invalid input!\n");
        free(newAccount);
        return;
    }

    if (newAccount->type != 1 && newAccount->type != 2) {
        printf("Invalid account type!\n");
        free(newAccount);
        return;
    }

    printf("Enter opening balance: Rs. ");

    if (scanf("%lf", &newAccount->balance) != 1) {
        printf("Invalid input!\n");
        free(newAccount);
        return;
    }

    if (newAccount->balance < 0) {
        printf("Invalid balance!\n");
        free(newAccount);
        return;
    }

    newAccount->accNo = nextAccNo++;
    newAccount->next = NULL;

    if (head == NULL) {
        head = newAccount;
    } else {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newAccount;
    }

    printf("\nAccount created successfully!\n");
    printf("Account Number: %d\n", newAccount->accNo);
}

void displayAccounts(void) {
    struct Account *temp = head;

    if (head == NULL) {
        printf("No accounts available!\n");
        return;
    }

    printf("\n========== ALL ACCOUNTS ==========\n");

    while (temp != NULL) {
        printf("\nAccount Number: %d\n", temp->accNo);
        printf("Name: %s\n", temp->name);
        printf("Type: %s\n",
               temp->type == 1 ? "Savings" : "Current");
        printf("Balance: Rs. %.2f\n", temp->balance);

        temp = temp->next;
    }
}

void searchAccount(void) {
    int number;
    struct Account *account;

    printf("Enter account number: ");

    if (scanf("%d", &number) != 1) {
        printf("Invalid input!\n");
        return;
    }

    account = search(number);

    if (account == NULL) {
        printf("Account not found!\n");
        return;
    }

    printf("\nAccount Number: %d\n", account->accNo);
    printf("Name: %s\n", account->name);
    printf("Type: %s\n",
           account->type == 1 ? "Savings" : "Current");
    printf("Balance: Rs. %.2f\n", account->balance);
}

int addTransaction(int type, int accNo, int receiver, double amount) {
    struct Transaction *newTransaction;

    newTransaction = (struct Transaction *)malloc(
        sizeof(struct Transaction)
    );

    if (newTransaction == NULL) {
        printf("Could not record transaction!\n");
        return 0;
    }

    newTransaction->id = nextTransID++;
    newTransaction->type = type;
    newTransaction->accNo = accNo;
    newTransaction->receiver = receiver;
    newTransaction->amount = amount;

    newTransaction->next = top;
    top = newTransaction;

    return 1;
}

void deposit(void) {
    int number;
    double amount;
    struct Account *account;

    printf("Enter account number: ");

    if (scanf("%d", &number) != 1) {
        printf("Invalid input!\n");
        return;
    }

    account = search(number);

    if (account == NULL) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter deposit amount: Rs. ");

    if (scanf("%lf", &amount) != 1) {
        printf("Invalid input!\n");
        return;
    }

    if (amount <= 0) {
        printf("Amount must be positive!\n");
        return;
    }

    if (!addTransaction(1, number, 0, amount))
        return;

    account->balance += amount;

    printf("Deposit successful!\n");
    printf("New Balance: Rs. %.2f\n", account->balance);
}

void withdraw(void) {
    int number;
    double amount;
    struct Account *account;

    printf("Enter account number: ");

    if (scanf("%d", &number) != 1) {
        printf("Invalid input!\n");
        return;
    }

    account = search(number);

    if (account == NULL) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter withdrawal amount: Rs. ");

    if (scanf("%lf", &amount) != 1) {
        printf("Invalid input!\n");
        return;
    }

    if (amount <= 0) {
        printf("Amount must be positive!\n");
        return;
    }

    if (amount > account->balance) {
        printf("Insufficient balance!\n");
        return;
    }

    if (!addTransaction(2, number, 0, amount))
        return;

    account->balance -= amount;

    printf("Withdrawal successful!\n");
    printf("New Balance: Rs. %.2f\n", account->balance);
}

void transfer(void) {
    int senderNo, receiverNo;
    double amount;

    struct Account *sender, *receiver;

    printf("Enter sender account number: ");

    if (scanf("%d", &senderNo) != 1) {
        printf("Invalid input!\n");
        return;
    }

    printf("Enter receiver account number: ");

    if (scanf("%d", &receiverNo) != 1) {
        printf("Invalid input!\n");
        return;
    }

    if (senderNo == receiverNo) {
        printf("Accounts must be different!\n");
        return;
    }

    sender = search(senderNo);
    receiver = search(receiverNo);

    if (sender == NULL || receiver == NULL) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter transfer amount: Rs. ");

    if (scanf("%lf", &amount) != 1) {
        printf("Invalid input!\n");
        return;
    }

    if (amount <= 0) {
        printf("Amount must be positive!\n");
        return;
    }

    if (amount > sender->balance) {
        printf("Insufficient balance!\n");
        return;
    }

    if (!addTransaction(3, senderNo, receiverNo, amount))
        return;

    sender->balance -= amount;
    receiver->balance += amount;

    printf("Transfer successful!\n");
    printf("Sender Balance: Rs. %.2f\n", sender->balance);
    printf("Receiver Balance: Rs. %.2f\n", receiver->balance);
}

void closeAccount(void) {
    int number;
    struct Account *temp = head;
    struct Account *prev = NULL;

    printf("Enter account number to close: ");

    if (scanf("%d", &number) != 1) {
        printf("Invalid input!\n");
        return;
    }

    while (temp != NULL && temp->accNo != number) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Account not found!\n");
        return;
    }

    if (temp->balance > 0.005 || temp->balance < -0.005) {
        printf("Withdraw or transfer the remaining balance first!\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Account closed successfully!\n");
}

void transactionHistory(void) {
    struct Transaction *temp = top;

    if (top == NULL) {
        printf("No transactions available!\n");
        return;
    }

    printf("\n========== TRANSACTION HISTORY ==========\n");

    while (temp != NULL) {
        printf("\nTransaction ID: %d\n", temp->id);

        if (temp->type == 1) {
            printf("Type: Deposit\n");
            printf("Account: %d\n", temp->accNo);
        } else if (temp->type == 2) {
            printf("Type: Withdrawal\n");
            printf("Account: %d\n", temp->accNo);
        } else {
            printf("Type: Transfer\n");
            printf("Sender: %d\n", temp->accNo);
            printf("Receiver: %d\n", temp->receiver);
        }

        printf("Amount: Rs. %.2f\n", temp->amount);

        temp = temp->next;
    }
}

void freeMemory(void) {
    struct Account *a;
    struct Transaction *t;

    while (head != NULL) {
        a = head;
        head = head->next;
        free(a);
    }

    while (top != NULL) {
        t = top;
        top = top->next;
        free(t);
    }
}

int main(void) {
    int choice;

    do {
        printf("\n====================================\n");
        printf("     BANKING MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Close Account\n");
        printf("5. Deposit Money\n");
        printf("6. Withdraw Money\n");
        printf("7. Transfer Money\n");
        printf("8. Transaction History\n");
        printf("0. Exit\n");
        printf("====================================\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                searchAccount();
                break;
            case 4:
                closeAccount();
                break;
            case 5:
                deposit();
                break;
            case 6:
                withdraw();
                break;
            case 7:
                transfer();
                break;
            case 8:
                transactionHistory();
                break;
            case 0:
                printf("Thank you for using our banking system!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    freeMemory();

    return 0;
}