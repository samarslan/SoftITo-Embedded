//
// Created by Samet Arslan on 9.09.2025.
//

#include <stdio.h>
#include <stdint.h>

uint32_t strlen(char* buffer) {
    uint32_t i=0;
    while (*(buffer+i)!='\0') {
        i++;
    }
    return i;
}

void strcat(char* buffer1, char* buffer2) {
    uint32_t length1 = strlen(buffer1);
    uint32_t length2 = strlen(buffer2);
    char *c = buffer1+length1;

    for (uint32_t i=0;i<length2;i++) {
        *(c+i) = buffer2[i];
    }
}

int main() {
    char buffer[] = "samet";
    char *pname = buffer;
    uint32_t length = strlen(buffer);


    // pname=pname+length;
    // *pname = 'x';
    // pname++;
    // *pname = 'y';
    // pname++;
    // *pname = '\0';


    strcat(buffer, "mahmut");
    for (uint32_t j=0;j<11;j++) {
        printf("%c",buffer[j]);
    }
    return 0;
}
