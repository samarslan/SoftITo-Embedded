//
// Created by Samet Arslan on 7.08.2025.
//

#include <stdio.h>

#define SIZE(dizi) (sizeof(dizi) / sizeof((dizi)[0]))

void printArray(int dizi[], int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

int findMin(int dizi[], int index, int length, int min_index) {
    if (index >= length)
        return min_index;

    if (dizi[index] < dizi[min_index])
        min_index = index;

    return findMin(dizi, index + 1, length, min_index);
}

void recursiveSelectionSort(int dizi[], int size, int start) {
    if (start >= size - 1)
        return;

    int min_index = findMin(dizi, start + 1, size, start);

    int temp = dizi[start];
    dizi[start] = dizi[min_index];
    dizi[min_index] = temp;

    recursiveSelectionSort(dizi, size, start + 1);
}

int main() {
    int dizi[] = {3, 38, 12, 124, 11, 2323, 2425, -15};

    printArray(dizi, SIZE(dizi));

    recursiveSelectionSort(dizi, SIZE(dizi), 0);

    printArray(dizi, SIZE(dizi));

    return 0;
}
