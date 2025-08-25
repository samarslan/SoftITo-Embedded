//
// Created by Samet Arslan on 25.08.2025.
//

#include <stdio.h>

void foo(int x) {
    x=200;
}

void foo2(int *x) {
    *x=300;
}

int main() {
    int x=500;
    printf("x=%d\n", x);

    foo(x);
    printf("x=%d\n", x);

    foo2(&x);
    printf("x=%d\n", x);
}