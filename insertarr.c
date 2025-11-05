#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int* arr = (int*)malloc(sizeof(int)*7);
    for (int i = 0; i < 8; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    int val = 4;
    int pos = 4;

    for (int i = 7; i > pos - 1; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos - 1] = val;
    
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
}