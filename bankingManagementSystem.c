#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

struct Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function to create a new account
void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Bank is full. Cannot add more accounts.\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &accounts[accountCount].accountNumber);
    printf("Enter name: ");
    scanf("%s", accounts[accountCount].name);
    printf("Enter initial deposit amount: ");
    scanf("%f", &accounts[accountCount].balance);

    accountCount++;
    printf("Account created successfully!\n");
}

// Function to deposit money
void depositMoney() {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Amount deposited successfully! Current balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to withdraw money
void withdrawMoney() {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient balance!\n");
            } else {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully! Current balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to check balance
void checkBalance() {
    int accNum;
    printf("Enter account number: ");
    scanf("%d", &accNum);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Current Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to display all accounts
void displayAccounts() {
    if (accountCount == 0) {
        printf("No accounts to display.\n");
        return;
    }

    printf("\n--- Account Details ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %.2f\n\n", accounts[i].balance);
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Banking Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: checkBalance(); break;
            case 5: displayAccounts(); break;
            case 6: printf("Exiting system. Goodbye!\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
