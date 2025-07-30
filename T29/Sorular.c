//
// Created by Samet Arslan on 29.07.2025.
//

#include <stdio.h>


int ornek1(int x) {
    int n=1;
    while (x>1) {
        if (x/10>=1) {
            n++;
            x=x/10;
        }
        else
            break;
    }
    return n;
}

int ornek2(int a, int b) {
    int t=a;
    for (int i=1; i<b; i++) {
        t=t*a;
    }
    return t;
}

void ornek3(int x) {
    printf("%d\n",x);
    while (x>1) {
        if (x%2==0) {
            x=x/2;
        }
        else {
            x = 3*x+1;
        }
        printf("%d\n",x);
    }
}

void ornek4(int x) {
    for (int i=1; i<x; i++) {
        for (int j=1; j<i; j++)
            printf("*");
        printf("\n");
    }
    for (int i=x; i>0; i--) {
        for (int j=1; j<i; j++)
            printf("*");
        printf("\n");
    }
}

void ornek5() {
    for (int i=1; i<10; i++) {
        for (int j=1; j<10; j++) {
            printf("%d x %d = %d",  i, j, i*j);
            printf("   ");
        }
        printf("\n");
    }
}

int ornek6(int hours,int minutes, int seconds) {
    minutes=minutes+hours*60;
    seconds=seconds+minutes*60;
    return seconds;
}

int main() {
    //printf("%d",ornek1(100000));

    //printf("%d",ornek2(5,5));

    //ornek3(20);

    // ornek4(10);

    ornek5();

    //printf("%d", ornek6(1,0,5));
}