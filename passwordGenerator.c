#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void generatePassword(int length);

int main() {
    int choice, length;

    printf("=== Welcome to the Password Generator ===\n");

    do {
        printf("\nMenu:\n");
        printf("1. Generate Password\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the desired password length (minimum 6): ");
                scanf("%d", &length);
                if (length < 6) {
                    printf("\nPassword length must be at least 6. Try again.\n");
                } else {
                    generatePassword(length);
                }
                break;
            case 2:
                printf("\nThank you for using the Password Generator. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}

// Function to generate a random password
void generatePassword(int length) {
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                        "abcdefghijklmnopqrstuvwxyz"
                        "0123456789"
                        "!@#$%^&*()_+";
    int charSetSize = sizeof(characters) - 1; // Exclude the null terminator
    char password[length + 1];               // +1 for null terminator

    srand(time(0)); // Seed for random number generation

    for (int i = 0; i < length; i++) {
        password[i] = characters[rand() % charSetSize];
    }
    password[length] = '\0'; // Null-terminate the password

    printf("\nGenerated Password: %s\n", password);
}
