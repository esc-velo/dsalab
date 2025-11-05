#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// WAP to create a structure wich contains 3 fields: reg no of students, name, AND CGPA.
typedef struct {
    int reg_no;
    char name[50];
    float cgpa;
} Student;

int main() {
    int n = 3;

    Student* students;

    // Allocate the memory for the structure students using dynamic memory allocation for 10 students.
    students = (Student*)malloc(n * sizeof(Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter details for 10 students:\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter Registration Number: ");
        scanf("%d", &students[i].reg_no);
        printf("Enter Name: ");
        scanf("%s", students[i].name);
        printf("Enter CGPA: ");
        scanf("%f", &students[i].cgpa);
    }

    printf("\n--- Student Details ---\n");

    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Registration Number: %d\n", students[i].reg_no);
        printf("Name: %s\n", students[i].name);
        printf("CGPA: %.2f\n", students[i].cgpa);
        printf("-----------------------\n");
    }

    free(students);
    students = NULL;

    return 0;
}
