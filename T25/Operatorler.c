//
// Created by Samet Arslan on 7/25/25.
//

#include <stdio.h>

int f1() {
    return 5;
}

int f2() {
    return 10;
}

int f3() {
    return 3;
}




int main() {
    int ival= 0b10110110101;

    int result = f1()+f2()*5;

    printf("%d",result);
}
