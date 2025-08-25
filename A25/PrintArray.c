//
// Created by Samet Arslan on 25.08.2025.
//

#include <stdio.h>

void printArray(int arr[], int size) {
    for (int j = 0; j < size; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
}

void printArray2(int arr[], int size) {
    int i=0;
    while (i<size) {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

void printArray3(int arr[], int size) {
    int i=0;
    do{
        printf("%d ", arr[i]);
        i++;
    }while(i<size);
    printf("\n");
}

int main() {
    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    printArray3(array, 10);
}