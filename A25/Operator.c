//
// Created by Samet Arslan on 25.08.2025.
//

#include <stdio.h>

int main() {
    int x = 10, y = 30;
    int *ptr = &x;
    *ptr = 20;

    ptr = &y;
    *ptr = 300;
    printf("x=%d y=%d ptr=%d\n", x, y, *ptr);
}
