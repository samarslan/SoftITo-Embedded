//
// Created by Samet Arslan on 8.08.2025.
//

#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {,
    int matris[ROWS][COLS];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            matris[i][j] = 5;
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
    return 0;
}
