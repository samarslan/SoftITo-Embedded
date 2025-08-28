//
// Created by Samet Arslan on 28.08.2025.
//

#include <stdio.h>

void copyArray(const int* originalArray, int* targetArray, int copyLen, int targetLen);
void printArray(const int* array, int len);

void copyArray(const int* originalArray, int* targetArray, int copyLen, int targetLen){
    int i=0;
    for (i = 0; i < copyLen; i++) {
        targetArray[i] = originalArray[i];
    }
    for (; i < targetLen; i++) {
        targetArray[i] = 0;
    }
}

void printArray(const int* array, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    const int array[] = {1,5,7,9,3};
    printArray(array, 5);

    int array2[3];
    copyArray(array, array2, 3, 3);
    printArray(array2, 3);

    int array3[8] = {1,2,3,4,5,6,7};
    copyArray(array, array3, 3, 8);
    printArray(array3, 8);

    return 0;
}