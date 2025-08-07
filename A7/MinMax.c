//
// Created by Samet Arslan on 7.08.2025.
//

#include <stdio.h>

int main() {
    int dizi[] = {10, 5, 23, -4, 99, 3};

    int min = dizi[0];
    int max = dizi[0];

    for (int i = 1; i < 6; i++) {
        if (dizi[i] < min) {
            min = dizi[i];
        }
        if (dizi[i] > max) {
            max = dizi[i];
        }
    }

    printf("Min: %d\n", min);
    printf("Max: %d\n", max);

    return 0;
}