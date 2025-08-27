//
// Created by Samet Arslan on 27.08.2025.
//

#include <stdio.h>

int main() {

    int a = 0b01000110;
    unsigned int getA;


    printf("a = %b\n", a);
    getA |= (0u<<2);
    printf("getA = %b\n", getA);
}