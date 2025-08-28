//
// Created by Samet Arslan on 28.08.2025.
//

#include <stdio.h>

int main() {
    int array[] = {1,2,3,4,5,6,7,8,10};

    printf("%d", array[0]);

    int *ptr = &array[0];
    printf("\n");
    printf("%d", *ptr+1);
}
