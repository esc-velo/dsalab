#include <stdio.h>

int main (void) {

    // a. Creating an Array of N Integer Elements

    int n;
    printf("Enter the no of elements: ");
    scanf("%d", &n);
    int arr[n+1];

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    // b. Display of Array Elements with Suitable Headings

    for (int j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");

    // c. Inserting an Element (ELEM) at a given valid Position (POS)
    int pos, elem;
    printf("Enter number to insert: ");
    scanf("%d", &elem);

    printf("Enter position of element to be inserted: ");
    scanf("%d", &pos);

    for (int i = n; i > pos - 2; i--) {
        arr[i+1] = arr[i];
    }
    arr[pos - 1] = elem;

    printf("\n");

    printf("Number inserted.");

    printf("\n");

    for (int j = 0; j < n+1; j++) {
        printf("%d ", arr[j]);
    }

    printf("\n");

    // d. Deleting an Element at a given valid Position(POS)

    printf("Enter position of element to be deleted: ");
    scanf("%d", &pos);

    for (int i = pos; i < n; i++) {
        arr[i - 1] = arr[i];
    }

    printf("\n");

    printf("Number deleted.");

    printf("\n");

    for (int j = 0; j < n; j++) {
        printf("%d ", j+1);
    }

    // e. Exit.
    return 0;
}