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

    for (int row = 0; row < ROWS; row++) {
        int rowTotal=0;
        for (int col = 0; col < COLS; col++) {
            rowTotal+=matris[row][col];
        }
        printf("\n");
        printf("row total at %d =%4d",row, rowTotal);
        printf("\n");
        printf("row avg at %d = %0.3f", row, (double)rowTotal/(COLS));
        printf("\n");
    }

    return 0;
}