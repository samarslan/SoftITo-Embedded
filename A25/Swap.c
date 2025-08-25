//
// Created by Samet Arslan on 25.08.2025.
//

#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int a = 10;
    int b = 20;

    swap(&a, &b);

    printf("a = %d\n",a);
    printf("b = %d\n",b);
}