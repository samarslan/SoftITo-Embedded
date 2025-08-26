//
// Created by Samet Arslan on 26.08.2025.
//

#include "utility.h"

void printArray(const int *pa, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", pa[i]);
    printf("\n");
}

unsigned int getBetterSeed() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (unsigned int)(tv.tv_sec ^ tv.tv_usec ^ getpid());
}

void setRandomArray(int arr[], const int size) {
    for (int j = 0; j < size; j++) {
        arr[j] = rand() % 100;
    }
}

int* createRandomArray(const int size) {
    if (size > 0) {
        int *pa  = (int *)malloc(size * sizeof(int));
        setRandomArray(pa, size);
        return pa;
    }
    return NULL;
}

int sumArray(const int *pa, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += pa[i];
    }
    return total;
}
