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

    for (int col = 0; col < COLS; col++) {
        int colTotal=0;
        for (int row = 0; row < ROWS; row++) {
            colTotal+=matris[row][col];
        }
        printf("\n");
        printf("col total at %d =%4d",col, colTotal);
        printf("\n");
        printf("col avg at %d = %0.3f", col, (double)colTotal/(ROWS));
        printf("\n");
    }

    return 0;
}