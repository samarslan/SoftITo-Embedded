//
// Created by Samet Arslan on 31.07.2025.
//

#include <stdio.h>

#define MUTLAK(x) ((x) < 0 ? -(x) : (x))

int main() {
    int x=-255;
    printf("%d\n", MUTLAK(x));
}