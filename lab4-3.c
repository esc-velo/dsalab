// Create 2D arrays, A and B dynamically and perform addition, subtraction and muliplication.

#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate a 2D array
int **allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free dynamically allocated 2D array
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to print a 2D array
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int r1, c1, r2, c2;

    // Input matrix dimensions
    printf("Enter rows and cols for matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and cols for matrix B: ");
    scanf("%d %d", &r2, &c2);

    // Allocate matrices
    int **A = allocateMatrix(r1, c1);
    int **B = allocateMatrix(r2, c2);

    // Input elements of A
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input elements of B
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Addition & Subtraction (only if dimensions match)
    if (r1 == r2 && c1 == c2) {
        int **add = allocateMatrix(r1, c1);
        int **sub = allocateMatrix(r1, c1);

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                add[i][j] = A[i][j] + B[i][j];
                sub[i][j] = A[i][j] - B[i][j];
            }
        }

        printf("\nAddition of A and B:\n");
        printMatrix(add, r1, c1);

        printf("Subtraction of A and B (A-B):\n");
        printMatrix(sub, r1, c1);

        freeMatrix(add, r1);
        freeMatrix(sub, r1);
    } else {
        printf("\nAddition and Subtraction not possible (dimension mismatch).\n");
    }

    // Multiplication (only if c1 == r2)
    if (c1 == r2) {
        int **mul = allocateMatrix(r1, c2);

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                mul[i][j] = 0;
                for (int k = 0; k < c1; k++) {
                    mul[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        printf("Multiplication of A and B:\n");
        printMatrix(mul, r1, c2);

        freeMatrix(mul, r1);
    } else {
        printf("\nMultiplication not possible (A's columns != B's rows).\n");
    }

    // Free original matrices
    freeMatrix(A, r1);
    freeMatrix(B, r2);

    return 0;
}
