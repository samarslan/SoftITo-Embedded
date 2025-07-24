//
// Created by Samet Arslan on 7/24/25.
//

#include <stdio.h>

int sum(int a, int b){
    int sum=a+b;
    return sum;
}

int findGreater(int a, int b, int c) {
    if(a>b && a>c) {
        return a;
    }
    else if(b>a && b>c) {
        return b;
    }
    else {
        return c;
    }
}

int findSmaller(int a, int b, int c) {
    if(a<b && a<c) {
        return a;
    }
    else if(b<a && b<c) {
        return b;
    }
    else {
        return c;
    }
}

int getCube(int a) {
    return a*a*a;
}

int main(){
    printf("%d\n", findGreater(3, 4, 5));
    printf("%d\n", findSmaller(3, 4, 5));
    printf("%d\n", getCube(3));
}