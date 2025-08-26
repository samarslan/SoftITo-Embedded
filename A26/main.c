//
// Created by Samet Arslan on 26.08.2025.
//

#include "utility.c"

int main() {
    srand(getBetterSeed());

    int arraySize1 = rand() % 100;
    int arraySize2 = rand() % 100;

    int *array1 = createRandomArray(arraySize1);
    int array2[arraySize2];
    setRandomArray(array2, arraySize2);

    printArray(array1, arraySize1);
    printArray(array2, arraySize2);

    int sum = sumArray(array1, arraySize1);
    int sum2 = sumArray(array2, arraySize2);

    printf("array1 = %d\n", sum);
    printf("array2 = %d\n", sum2);
}
