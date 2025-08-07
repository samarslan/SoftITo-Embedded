//
// Created by Samet Arslan on 7.08.2025.
//

#include <stdio.h>

#define SIZE(dizi) (sizeof(dizi) / sizeof((dizi)[0]))

void kendisiKadarYazdir(int dizi[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < dizi[i]; j++) {
            printf("%d  ", dizi[i]);
        }
    }
}

void indexKadarYazdir(int dizi[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            printf("%d  ", dizi[i]);
        }
    }
}

int main() {
    int dizi[] = {1,2,3,4,5,6,7};
    kendisiKadarYazdir(dizi, SIZE(dizi));
    printf("\n");
    indexKadarYazdir(dizi, SIZE(dizi));
}