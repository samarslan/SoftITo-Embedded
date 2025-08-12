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

    int max[ROWS];
    int min[ROWS];

    for (int row = 0; row < ROWS; row++) {
        int row_max=matris[row][0];
        int row_min=matris[row][0];
        for (int col = 0; col < COLS; col++) {
            if (row_max < matris[row][col]) {
                row_max = matris[row][col];
            }
            if (row_min > matris[row][col]) {
                row_min = matris[row][col];
            }
        }
        max[row] = row_max;
        min[row] = row_min;
    }

    int minElement = min[0];
    int maxElement = max[0];

    for (int row = 0; row < ROWS; row++) {
        if (maxElement < max[row]) {
            maxElement = max[row];
        }
        if (minElement > min[row]) {
            minElement = min[row];
        }
    }

    printf("\n");
    printf("Max: %d\n", maxElement);
    printf("Min: %d\n", minElement);

    return 0;
}