//
// Created by Samet Arslan on 8.08.2025.
//

#include <stdio.h>

#define ROWS 4
#define COLS 3

int main() {
    int matris[ROWS][COLS];

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            matris[row][col] = col+1;
        }
    }

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%d ", matris[row][col]);
        }
        printf("\n");
    }

    return 0;
}
