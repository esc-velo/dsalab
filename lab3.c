#include <stdio.h>
#include <stdbool.h>

// linear search
void linearS(int arr[], int n, int find) {
    bool found = false;
    for(int i = 0; i < n; i++) {
        if (arr[i] == find) {
            found = true;
            printf("Found at position %d", i+1);
            break;
        }
    }
    if (!found) {
        printf("Not found");
    }
}

// binary search using iterative approach

int binaryS(int arr[], int n, int find) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == find) {
            return mid;
        }
        else if (arr[mid] > find) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

// binary search using recursive approach

int binarySrec(int arr[], int low, int high, int find) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == find) 
        return mid;
    else if (find > arr[mid])
        return binarySrec(arr, mid + 1, high, find);
    else
        return binarySrec(arr, low, mid - 1, find);
}

// bubble sort
void bubbleSort(int arr[], int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) { // ----- n - 1 times
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) { // ----- n * (n - i - 1)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

// O (n^2)

int main () {
    int n, find;

    printf("Enter no of elements of the array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter element to find: ");
    scanf("%d", &find);

    bubbleSort(arr,n);

    int res = binaryS(arr, n, find);

    if (res == -1) {
        printf("Element not found");
    }

    return 0;
}