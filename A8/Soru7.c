//
// Created by Samet Arslan on 8.08.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

int main() {

    srand(time(NULL));

    int matris[ROWS][COLS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            matris[row][col] = rand()%1000;
        }
    }
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%4d ", matris[row][col]);
        }
        printf("\n");
    }
    printf("\n\n");

    int maxValue = matris[0][0];
    int maxRow = 0;
    int maxCol = 0;

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (matris[row][col] > maxValue) {
                maxValue = matris[row][col];
                maxRow = row;
                maxCol = col;
            }
        }
    }

    printf("Max: %d\n", maxValue);
    printf("Index:\nRow:%d\nColumn:%d", maxRow, maxCol);

    return 0;
}