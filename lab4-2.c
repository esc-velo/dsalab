#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int* numbers;
    long long sum = 0;
    float average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Check for invalid input
    if (n <= 0) {
        printf("Number of elements must be a positive integer.\n");
        return 1;
    }

    // Dynamically allocate memory for n integers
    numbers = (int*)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integer elements:\n", n);
    // Loop to read elements and calculate sum
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    // Calculate the average
    average = (float)sum / n;

    printf("\n--- Results ---\n");
    printf("Sum of elements: %lld\n", sum);
    printf("Average of elements: %.2f\n", average);

    // Free the dynamically allocated memory
    free(numbers);
    numbers = NULL; // Set the pointer to NULL

    return 0;
}
