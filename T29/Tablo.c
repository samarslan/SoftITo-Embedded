//
// Created by Samet Arslan on 29.07.2025.
//

#include <stdio.h>

// void printTable() {
//     static int i = 1;
//     static int j = 1;
//
//     if (i >= 10)
//         return;
//
//     printf("%d x %d = %d   ", i, j, i * j);
//     j++;
//     if (j == 10) {
//         printf("\n");
//         j = 1;
//         i++;
//     }
//
//     printTable();
// }
// void ornek5() {
//     printTable();
// }
// int main() {
//     ornek5();
// }

//
// Created by Samet Arslan on 29.07.2025.
//


void tabloyuYazdir(int i, int j) {
    if (i >= 10)
        return;

    printf("%dx%d=%d\t", i, j, i * j);
    j++;
    if (j == 10) {
        printf("\n");
        j = 1;
        i++;
    }
    tabloyuYazdir(i, j);
}

int main() {
    tabloyuYazdir(1, 1);
}
