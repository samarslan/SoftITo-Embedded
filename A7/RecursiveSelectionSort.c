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

int main() {
    int dizi[] = {3, 38, 12, 124, 11, 2323, 2425, -15};
    int temp;

    printArray(dizi, SIZE(dizi));

    for (int i = 0; i < SIZE(dizi) - 1; i++) {
        int min_index = findMin(dizi, i + 1, SIZE(dizi), i);

        temp = dizi[i];
        dizi[i] = dizi[min_index];
        dizi[min_index] = temp;
    }

    printArray(dizi, SIZE(dizi));

    return 0;
}