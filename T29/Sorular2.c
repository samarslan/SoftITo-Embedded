//
// Created by Samet Arslan on 29.07.2025.
//


#include <stdio.h>

void diziyiYazdir(int a[], int b) {
    for (int j=0; j<b; j++) {
        printf("%d  ", a[j]);
    }
}

void ornek2() {
    int dizi[20];

    for (int j=0; j<20; j++) {
        dizi[j] = 7;
    }
    for (int j=0; j<20; j++) {
        printf("%d  ", dizi[j]);
    }
}

void ornek3() {
    int dizi[10];
    for (int j=0; dizi[9]!=9; j++) {
        if (j%2==0) {
            dizi[j] = j+2;
        }
        else {
            dizi[j] = 9;
        }
    }
    for (int j=0; j<10; j++) {
        printf("%d  ", dizi[j]);
    }
}

void ornek4() {
    int dizi[10];
    for (int j=0; dizi[9]!=9; j++) {
        if (j%2==0) {
            dizi[j] = j*2+2;
        }
        else {
            dizi[j] = 9;
        }
    }
    for (int j=0; j<10; j++) {
        printf("%d  ", dizi[j]);
    }
}

void ornek5() {
    int dizi[] = {4,7,1,3,9,3,7,3,5,2};
    int t=0;
    for (int j=0; j<10; j++) {
        t+=dizi[j];
    }
    printf("%d  ", t);
}

void ornek6() {
    int dizi[] = {4,7,1,3,9,3,7,3,5,2};

    for (int j=0; j<10; j++) {
        if (dizi[j]%2==1) {
            printf("%d  ", dizi[j]);
        }
    }
}

void ornek7() {
    int dizi[] = {4,7,1,3,9,3,7,3,5,2};
    int t=0;
    double n=0;

    for (int j=0; j<10; j++) {
        if (dizi[j]%2==1) {
            printf("%d  ", dizi[j]);
            t+=dizi[j];
            n++;
        }
    }
    printf("\n%d  ", t);
    printf("\n%f  ", t/n);
}

void ornek8() {
    int dizi[] = {4,7,1,3,9,3,7,3,5,2};
    int a=0;
    scanf("%d", &a);
    for (int j=0; j<10; j++) {
        if (dizi[j]<a) {
            printf("%d  ", dizi[j]);
        }
    }
}

void ornek9() {
    int dizi[] = {4,7,1,3,9,3,7,3,5,2};
    int a=0;
    scanf("%d", &a);
    for (int j=0; j<10; j++) {
        if (dizi[j]<a&&dizi[j]%2==1) {
            printf("%d  ", dizi[j]);
        }
    }
}

int main() {
    ornek4();
}