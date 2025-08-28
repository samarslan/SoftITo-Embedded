#include <stdio.h>

#define ARRAY_SIZE 7

void findGreatestAndSmallest(const int* array, int length, int* minAndMax) {
    int min=0;
    int max=0;

    for(int i=0;i<length;i++) {
        if (array[i]<min) {
            min = array[i];
        }
        if (array[i]>max) {
            max = array[i];
        }
    }

    minAndMax[0]=min;
    minAndMax[1]=max;
}

int main(void) {
    int array[] = {19,23,-14,15,222,13,1555};
    int minAndMax[2];

    findGreatestAndSmallest(&array, ARRAY_SIZE, &minAndMax);

    printf("%d", minAndMax[0]);
    printf("\n");
    printf("%d", minAndMax[1]);

    return 0;
}