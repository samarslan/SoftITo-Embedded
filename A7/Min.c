//
// Created by Samet Arslan on 7.08.2025.
//

#include <stdio.h>
#define SIZE 6

int main() {
    int dizi[] = {10, 5, 23, -4, 99, 3};
    int min_index;
    int min = dizi[0];

    for (int i = 1; i < SIZE; i++) {
        if (dizi[i] < min) {
            min_index = i;
            min = dizi[i];

        }
    }
    dizi[min_index] = dizi[0];
    dizi[0]=min;

    printf("En küçük: %d\n", dizi[0]);

    return 0;
}