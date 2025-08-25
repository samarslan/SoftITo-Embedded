//
// Created by Samet Arslan on 25.08.2025.
//

#include <stdio.h>

int main() {
    int a = 5;
    int *p = &a;

    printf("Address:%p\n", p);
    printf("Value:%d\n", *p);

    printf("\n");

    int b = 10;
    p = &b;

    printf("Address:%p\n", p);
    printf("Value:%d\n", *p);

    printf("\n");

    printf("Pointer Size:%lu\n", sizeof(p));
    printf("Pointer Value size:%lu\n", sizeof(*p));
}
