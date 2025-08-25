//
// Created by Samet Arslan on 25.08.2025.
//


#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void setRandomArray(int arr[], const int size) {
    for (int j = 0; j < size; j++) {
        arr[j] = rand() % 100;
    }
}

void printArray(const int arr[], const int size) {
    for (int j = 0; j < size; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int size = rand() % 100;
    int arr[size];

    setRandomArray(arr, size);
    printArray(arr, size);

}

