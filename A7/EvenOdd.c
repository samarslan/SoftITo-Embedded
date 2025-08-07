//
// Created by Samet Arslan on 7.08.2025.
//

#include <stdio.h>

#define SIZE 10

int main() {
    int a[]={4,8,3,1,18,9,21,20,5,17};
    int b[SIZE];

    for (int i=0;i<SIZE;i++) {
        if (a[i]%2!=0) {
            b[i]=a[i];
        }
    }
    for (int i=SIZE-1;i>=0;i--) {
        if (a[i]%2==0) {
            b[i]=a[i];
        }
    }
    for (int i=0;i<SIZE;i++) {
        printf("%d ", b[i]);
    }
}