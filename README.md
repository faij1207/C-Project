# Project Collection in C

This repository contains five C projects that demonstrate basic programming concepts such as file handling, loops, conditional statements, arrays, and more. These projects are designed to provide a practical understanding of different types of programs that solve real-world problems.

## 1. Password Generator

**Description:**
A program that generates random passwords of varying lengths, including uppercase, lowercase, digits, and special characters.

**Features:**

- Generate strong passwords with random characters.
- Customizable password length input by the user.
- User-friendly interface for interacting with the program.

**Concepts:**

- Random number generation
- Arrays
- Loops
- User interaction

**Example Output:**

```plaintext
Enter the password length: 12
Generated Password: Ab8@7cD1fX$9
```

## 2. Prime Number Finder

**Description:**
This program finds all prime numbers within a given range input by the user.

**Features:**

- User inputs the range (lower and upper bounds).
- Finds all prime numbers within the range.
- Efficient prime checking using square root method.

**Concepts:**

- Nested loops
- Conditional statements
- Prime number checking

**Example Output:**

```plaintext
Enter the lower bound of the range: 10
Enter the upper bound of the range: 50

Prime numbers between 10 and 50 are:
11 13 17 19 23 29 31 37 41 43 47
```

## 3. Student Report Card System

**Description:**
A system to manage student details, including adding, deleting, updating, and displaying student records. The program calculates the average marks and assigns a grade.

**Features:**

- Add, update, and delete student details.
- Automatically calculates grades based on the average marks.
- Displays a list of all students with their grades.

**Concepts:**

- Arrays
- File handling
- Functions
- Structs

**Example Output:**

```plaintext
Enter Roll Number: 101
Enter Name: John Doe
Enter marks for 5 subjects:
Subject 1: 85
Subject 2: 90
Subject 3: 78
Subject 4: 92
Subject 5: 88

Student added successfully!

Enter Roll Number to update: 101
Enter new details for Roll Number 101:
Enter Name: John Doe Updated
Enter marks for 5 subjects:
Subject 1: 88
Subject 2: 91
Subject 3: 80
Subject 4: 85
Subject 5: 90

Student details updated successfully!

=== Student Report Cards ===
Roll No.        Name                  Average Grade
-------------------------------------------------
101             John Doe Updated      86.80   A
```

## 4. Number Guessing Game

**Description:**
A simple number guessing game where the player has to guess a randomly generated number within a specified range.

**Features:**

- The program generates a random number within a range.
- The player guesses the number, with feedback provided for each guess (too high, too low, correct).
- Counts the number of attempts until the correct guess is made.

**Concepts:**

- Randomization
- Loops
- User input/output
- Conditional statements

**Example Output:**

```plaintext
Welcome to the Number Guessing Game!

Guess the number between 1 and 100:
Your guess: 50
Too high! Try again.

Your guess: 25
Too low! Try again.

Your guess: 37
Correct! You guessed the number in 3 attempts.
```

## 5. Library Management System

**Description:**
A basic library management system that allows the user to add books, issue books, return books, and view book details.

**Features:**

- Add new books to the library.
- Issue and return books.
- View the list of all books in the library.
- File handling to store book information.

**Concepts:**

- File handling
- Arrays
- Structs
- Functions

**Example Output:**

```plaintext
=== Library Management System ===
1. Add Book
2. Issue Book
3. Return Book
4. View All Books
5. Exit
Enter your choice: 1

Enter Book Title: C Programming Basics
Enter Book Author: John Doe
Book added successfully!

=== Library Management System ===
1. Add Book
2. Issue Book
3. Return Book
4. View All Books
5. Exit
Enter your choice: 4

List of all books:
1. C Programming Basics by John Doe
```

## How to Run the Projects

Clone this repository to your local machine:

```bash
git clone https://github.com/faij1207/C-Project.git
```

Navigate to the project directory:

```bash
cd project-name
```

Compile the C programs:

```bash
gcc program_name.c -o program_name
```

Run the program:

```bash
./program_name
```

## Contributing

Feel free to fork this repository and contribute by submitting pull requests. If you have any suggestions or improvements, feel free to open an issue.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
