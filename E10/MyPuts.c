//
// Created by Samet Arslan on 10.09.2025.
//

#include<stdio.h>


int myPuts(char * str) {
    int i=0;
    while (str[i] != '\0') {
        putchar(str[i]);
        i++;
    }
    return i;
}

int main(void) {
    char name[100] = "mahmut";
    myPuts(name);

    return 0;
}


