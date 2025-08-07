//
// Created by Samet Arslan on 7.08.2025.
//

#include <stdio.h>
#define SIZE 5

int main() {
    int a[]={2,4,6,8,10};

    int temp=0;
    int first = a[0];

    for(int i=0;i<SIZE;i++) {
        temp=a[i+1];
        a[i]=temp;
    }

    a[SIZE-1]=first;
    for(int i=0;i<SIZE;i++) {
        printf("%d ", a[i]);
    }
}
