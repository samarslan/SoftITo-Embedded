//
// Created by Samet Arslan on 8.08.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    srand(time(NULL));

    int matris[ROWS][COLS];
    int tMatris[ROWS][COLS];

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            matris[row][col] = rand()%2;
        }
    }

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("\t%d ", matris[row][col]);
        }
        printf("\n");
    }

    printf("\n");

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            tMatris[row][col] = matris[row][COLS - 1 - col];
        }
    }

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("\t%d ", tMatris[row][col]);
        }
        printf("\n");
    }

    return 0;
}

