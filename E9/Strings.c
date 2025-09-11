//
// Created by Samet Arslan on 9.09.2025.
//

#include <stdio.h>
#include <stdint.h>

#define BUFFER_MAX_SIZE 2000

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
    uint32_t i=0;
    *(c+i++) = ' ';
    for (;i<length2+1;i++) {
        *(c+i) = buffer2[i-1];
    }
    *(c+i+1) = '\0';
}

int main() {
    char buffer[BUFFER_MAX_SIZE] = "Samet";
    strcat(buffer, "Arslan");

    puts(buffer);

    return 0;
}
