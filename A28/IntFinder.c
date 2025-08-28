//
// Created by Samet Arslan on 28.08.2025.
//

#include <stdio.h>

int* findElement(const int* array, int length, const int element) {
    int *elementptr = NULL;

    for (int i = 0; i < length; i++) {
        if (array[i] == element) {
            elementptr = &array[i];
        }
    }
    return elementptr;
}

int findElementIndex(const int* array, const int* element) {
    return element - array;
}

int main() {
    int array[10] = {1,2,3,4,5,6,7,8,9};

    for (int i = 0; i < 10; i++) {
        printf("Array[%d] = %d\n", i, array[i]);
    }

    printf("\n\n");

    int *elementptr = findElement(array, 10, 11);

    printf("\nElement Address:");
    printf("%p", elementptr);
    printf("\n");

    if (elementptr != NULL) {
        printf("Element Index:");
        printf("%d", findElementIndex(array, elementptr));
    }
    else {
        printf("nullptr");
    }
}