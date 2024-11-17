#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void playGame();

int main() {
    int choice;

    printf("=== Welcome to the Number Guessing Game! ===\n");

    do {
        printf("\nMenu:\n");
        printf("1. Play Game\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                playGame(); 
                break;
            case 2: 
                printf("\nThank you for playing! Goodbye!\n"); 
                exit(0);
            default: 
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}

// Function to play the game
void playGame() {
    int lower = 1, upper = 100, number, guess, attempts = 0;

    // Generate random number
    srand(time(0));
    number = (rand() % (upper - lower + 1)) + lower;

    printf("\nI have chosen a number between %d and %d. Try to guess it!\n", lower, upper);

    // Loop until the player guesses correctly
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < number) {
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            printf("Too high! Try again.\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != number);
}
