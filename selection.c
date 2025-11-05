#include <stdio.h>
#include <stdlib.h>

int* selectionS (int* arr, int n) {
    int min, temp;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        if (min != i) {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    return arr;
}

int main () {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int* res = selectionS(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
}