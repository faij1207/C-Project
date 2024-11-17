#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for book details
typedef struct {
    int id;
    char title[50];
    char author[50];
    int quantity;
} Book;

// Function declarations
void addBook();
void issueBook();
void returnBook();
void viewBooks();
void menu();

// Main function
int main() {
    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: issueBook(); break;
            case 3: returnBook(); break;
            case 4: viewBooks(); break;
            case 5: 
                printf("\nExiting the program. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Display the menu
void menu() {
    printf("\n\n=== Library Management System ===\n");
    printf("1. Add Book\n");
    printf("2. Issue Book\n");
    printf("3. Return Book\n");
    printf("4. View Books\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Add a new book
void addBook() {
    FILE *file = fopen("library.dat", "ab"); // Open file in append mode
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    Book b;
    printf("\nEnter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Title: ");
    getchar(); // Clear buffer
    fgets(b.title, sizeof(b.title), stdin);
    strtok(b.title, "\n"); // Remove trailing newline
    printf("Enter Author: ");
    fgets(b.author, sizeof(b.author), stdin);
    strtok(b.author, "\n"); // Remove trailing newline
    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);

    fwrite(&b, sizeof(Book), 1, file); // Write book details to file
    fclose(file);
    printf("\nBook added successfully!\n");
}

// Issue a book
void issueBook() {
    FILE *file = fopen("library.dat", "rb+"); // Open file in read/write mode
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    int id, found = 0;
    Book b;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(Book), 1, file)) {
        if (b.id == id) {
            found = 1;
            if (b.quantity > 0) {
                b.quantity--; // Decrease quantity
                fseek(file, -sizeof(Book), SEEK_CUR); // Move file pointer back
                fwrite(&b, sizeof(Book), 1, file);    // Update the record
                printf("\nBook issued successfully!\n");
            } else {
                printf("\nBook is out of stock!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\nBook not found!\n");
    }
    fclose(file);
}

// Return a book
void returnBook() {
    FILE *file = fopen("library.dat", "rb+"); // Open file in read/write mode
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    int id, found = 0;
    Book b;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(Book), 1, file)) {
        if (b.id == id) {
            found = 1;
            b.quantity++; // Increase quantity
            fseek(file, -sizeof(Book), SEEK_CUR); // Move file pointer back
            fwrite(&b, sizeof(Book), 1, file);    // Update the record
            printf("\nBook returned successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nBook not found!\n");
    }
    fclose(file);
}

// View all books
void viewBooks() {
    FILE *file = fopen("library.dat", "rb"); // Open file in read mode
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    Book b;
    printf("\n\n=== Book List ===\n");
    printf("ID\tTitle\t\t\tAuthor\t\t\tQuantity\n");
    printf("------------------------------------------------------------\n");

    while (fread(&b, sizeof(Book), 1, file)) {
        printf("%d\t%-20s\t%-20s\t%d\n", b.id, b.title, b.author, b.quantity);
    }
    fclose(file);
}
