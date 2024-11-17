#include <stdio.h>
#include <stdbool.h>

// Function declarations
bool isPrime(int number);
void findPrimesInRange(int lower, int upper);

int main() {
    int lower, upper;

    printf("=== Prime Number Finder ===\n");
    printf("Enter the lower bound of the range: ");
    scanf("%d", &lower);
    printf("Enter the upper bound of the range: ");
    scanf("%d", &upper);

    if (lower > upper || lower < 2) {
        printf("Invalid range! Lower bound must be at least 2, and upper bound must be greater than or equal to the lower bound.\n");
    } else {
        printf("\nPrime numbers between %d and %d are:\n", lower, upper);
        findPrimesInRange(lower, upper);
    }

    return 0;
}

// Function to check if a number is prime
bool isPrime(int number) {
    if (number <= 1) return false;

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }

    return true;
}

// Function to find and print all prime numbers in a given range
void findPrimesInRange(int lower, int upper) {
    for (int i = lower; i <= upper; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
