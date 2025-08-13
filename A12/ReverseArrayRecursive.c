//
// Created by Samet Arslan on 12.08.2025.
//

#include <stdio.h>

void reverse(int array[], int ilk, int son) {
    if (ilk >= son)
        return;

    int temp = array[ilk];
    array[ilk] = array[son];
    array[son] = temp;

    reverse(array, ilk + 1, son - 1);
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Dizi: ");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    reverse(array, 0, n - 1);


    printf("Ters dizi: ");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}
