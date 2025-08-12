//
// Created by Samet Arslan on 8.08.2025.
//

#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {

    int students_no[ROWS][COLS]={ {120,258,330,332},
{278,323,100,200},
{578,145,772,287}
    };

    int okuldaMi = 0;
    int sinif = 0;
    int no = 0;

    scanf("%d",&no);

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (students_no[row][col] == no) {
                okuldaMi=1;
                sinif=row+1;
                break;
            }
        }
    }
    printf("\n");
    if (okuldaMi==1) {
        printf("Öğrenci okulda.\nSınıfı: %d", sinif);
    }
    else {
        printf("Öğrenci okulda değil");
    }
}