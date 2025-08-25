//
// Created by Samet Arslan on 25.08.2025.
//

#include <stdio.h>

int main() {
    int x =10, y=20;
    double dval = 15.3;

    int *ptr = &x;
    printf("ptr:%p &x=%p", ptr, &x);
    ptr = &y;

    int **ptr2 = &ptr;

    printf("\n");
    printf("&x=%p &y=%p ptr=%p *ptr2=%p", &x,&y, ptr, *ptr2);

    return 0;
}
