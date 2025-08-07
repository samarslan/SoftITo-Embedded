//
// Created by Samet Arslan on 7.08.2025.
//

#include <stdio.h>

int main() {
    int a[5]= {2,4,6,8,10};
    int b[5];

    for (int i = 0; i < 5; i++) {
        b[i] = a[4-i];
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}
