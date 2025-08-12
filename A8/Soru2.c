//
// Created by Samet Arslan on 8.08.2025.
//

#include <stdio.h>
#define ROWS 4
#define COLS 3

int main() {
    int matris[ROWS][COLS];

    int count = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matris[i][j] = count;
            count++;
            printf("%2d ", matris[i][j]);
        }
        printf("\n");
    }
}