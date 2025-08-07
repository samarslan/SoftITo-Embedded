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

int main() {
    int dizi[] = {3, 38, 12, 124, 11, 2323, 2425, -15};
    int min_index, temp;

    printArray(dizi, SIZE(dizi));

    for (int i = 0; i < SIZE(dizi) - 1; i++) {
        min_index = i;

        for (int j = i + 1; j < SIZE(dizi); j++) {
            if (dizi[j] < dizi[min_index]) {
                min_index = j;
            }
        }

        temp = dizi[i];
        dizi[i] = dizi[min_index];
        dizi[min_index] = temp;
    }

    printArray(dizi, SIZE(dizi));

    return 0;
}
