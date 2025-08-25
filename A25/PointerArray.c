//
// Created by Samet Arslan on 25.08.2025.
//

#include <stdio.h>

int main() {
    int a[5] = {2,4,6,8,10};

    int *ptr2 = &a[2];
    int *p3 = &a[0];
    int *p4 = &a;

    printf("%p  %p %p", p3, a,&a[0]);
}
