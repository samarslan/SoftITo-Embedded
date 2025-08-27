//
// Created by Samet Arslan on 27.08.2025.
//

#include <stdio.h>

int main() {

    int a = 0b1010010;
    int b = 0b1010110;


    printf("a = %b\n", a);
    printf("b = %b\n", b);

    a ^= (1u<<2);
    b ^= (1u<<2);

    printf("a = %b\n", a);
    printf("b = %b\n", b);
}