#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
typedef struct {
    int rollNumber;
    char name[50];
    float marks[5];
    float average;
    char grade;
} Student;

// Function declarations
void addStudent();
void deleteStudent();
void updateStudent();
void displayStudents();
void calculateGrade(Student *s);

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n=== Student Report Card System ===\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudent(); break;
            case 4: displayStudents(); break;
            case 5:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a new student
void addStudent() {
    FILE *file = fopen("students.dat", "ab");
    if (!file) {
        printf("\nError opening file!\n");
        return;
    }

    Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.rollNumber);
    printf("Enter Name: ");
    getchar(); // Clear buffer
    fgets(s.name, sizeof(s.name), stdin);
    strtok(s.name, "\n"); // Remove newline character

    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &s.marks[i]);
    }

    calculateGrade(&s);
    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);

    printf("\nStudent added successfully!\n");
}

// Function to delete a student by roll number
void deleteStudent() {
    FILE *file = fopen("students.dat", "rb");
    FILE *tempFile = fopen("temp.dat", "wb");
    if (!file || !tempFile) {
        printf("\nError opening file!\n");
        return;
    }

    int roll, found = 0;
    Student s;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.rollNumber == roll) {
            found = 1;
            printf("\nStudent with Roll Number %d deleted successfully.\n", roll);
        } else {
            fwrite(&s, sizeof(Student), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (!found) {
        printf("\nStudent with Roll Number %d not found!\n", roll);
    }
}

// Function to update student details
void updateStudent() {
    FILE *file = fopen("students.dat", "rb+");
    if (!file) {
        printf("\nError opening file!\n");
        return;
    }

    int roll, found = 0;
    Student s;
    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.rollNumber == roll) {
            found = 1;
            printf("\nEnter new details for Roll Number %d:\n", roll);

            printf("Enter Name: ");
            getchar(); // Clear buffer
            fgets(s.name, sizeof(s.name), stdin);
            strtok(s.name, "\n");

            printf("Enter marks for 5 subjects:\n");
            for (int i = 0; i < 5; i++) {
                printf("Subject %d: ", i + 1);
                scanf("%f", &s.marks[i]);
            }

            calculateGrade(&s);
            fseek(file, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, file);

            printf("\nStudent details updated successfully!\n");
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("\nStudent with Roll Number %d not found!\n", roll);
    }
}

// Function to display all students
void displayStudents() {
    FILE *file = fopen("students.dat", "rb");
    if (!file) {
        printf("\nError opening file!\n");
        return;
    }

    Student s;
    printf("\n=== Student Report Cards ===\n");
    printf("Roll No.\tName\t\tAverage\tGrade\n");
    printf("-------------------------------------------------\n");

    while (fread(&s, sizeof(Student), 1, file)) {
        printf("%d\t\t%-20s\t%.2f\t%c\n", s.rollNumber, s.name, s.average, s.grade);
    }

    fclose(file);
}

// Function to calculate average and grade
void calculateGrade(Student *s) {
    float total = 0;
    for (int i = 0; i < 5; i++) {
        total += s->marks[i];
    }
    s->average = total / 5;

    if (s->average >= 90) {
        s->grade = 'A';
    } else if (s->average >= 75) {
        s->grade = 'B';
    } else if (s->average >= 50) {
        s->grade = 'C';
    } else {
        s->grade = 'F';
    }
}
