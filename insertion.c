#include <stdio.h>
#include <stdlib.h>

int* insertionS(int* arr, int n) {
    int key, temp, j;
    for (int i = 1; i <= n - 1; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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

    int* res = insertionS(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
}