//
// Created by Samet Arslan on 10.09.2025.
//

#include <string.h>
#include <stdio.h>

#define MAX_STRING_LENGTH 50
int main(void) {
    char name[MAX_STRING_LENGTH]="samet";
    char surname[MAX_STRING_LENGTH]="akçalar";
    char fullName[MAX_STRING_LENGTH];


 //   strcpy(fullName, name);
    strcat(strcat(strcpy(fullName, name), " "), surname);

    puts(fullName);

    return 0;
}