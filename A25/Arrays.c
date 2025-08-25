#include <stdio.h>

#define SIZE 6

void swap(int **x, int **y) {
    int *temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int *arr) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {7, 8, 9, 10, 11, 12};

    int *ptr = arr;
    int *ptr2 = arr2;

    printf("Before:\n");
    printArray(ptr);
    printArray(ptr2);

    swap(&ptr, &ptr2);

    printf("After:\n");
    printArray(ptr);
    printArray(ptr2);

    return 0;
}
