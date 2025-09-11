//
// Created by Samet Arslan on 11.09.2025.
//
#include <stdio.h>
#include <stdint.h>

#define MAX_STRING_SIZE 100

uint32_t strlen(const char* str) {
    uint32_t i=0;
    while (str[i]!='\0') {
        i++;
    }
    return i;
}

char* strcpy(char* dest, const char* source) {
    for (uint32_t i=0;i<strlen(source);i++) {
        dest[i]=source[i];
    }
    dest[strlen(source)]='\0';
    // returnn ???
}

void setFileExtension(char* fileName, const char* newExtension) {
    uint32_t fileNameLength = strlen(fileName);
    uint32_t newExtensionLength = strlen(newExtension);
    uint32_t oldExtensionLength = 0;
    char *dotPointer;
    uint32_t dotIndex=0;

    for (uint32_t i=0;i<fileNameLength;i++) {
        if (fileName[i]=='.') {
            dotPointer = fileName + i;
        }
    }

    uint32_t j=0;
    while((dotPointer[j])!='\0') {
        j++;
    }
    oldExtensionLength=j;

    uint32_t fileNameLengthWithoutOldExtension = fileNameLength-oldExtensionLength;

    dotIndex = dotPointer-fileName;

    uint32_t l=0;
    for (uint32_t i=dotIndex;i<fileNameLengthWithoutOldExtension+newExtensionLength;i++) {
        fileName[i+1]=newExtension[l];
        l++;
    }

    fileName[fileNameLengthWithoutOldExtension+newExtensionLength+1] = '\0';
}

char* strTrim(char* str) {
    char trimmedStr[MAX_STRING_SIZE];
    uint32_t strLength = strlen(str);
    uint32_t headWhitespaceCount=0;
    uint32_t endWhitespaceCount=0;

    uint32_t i=0;
    while(str[i]==' ') {
        i++;
    }
    headWhitespaceCount=i;

    uint32_t j=strLength-1;
    while (str[j]==' ') {
        j--;
    }
    endWhitespaceCount = strLength-1-j;


    uint32_t k=0;
    while (k<strLength-headWhitespaceCount-endWhitespaceCount) {
        trimmedStr[k]=str[headWhitespaceCount+k];
        k++;
    }

    for (uint32_t l=0; l<strlen(trimmedStr);l++) {
        str[l] = trimmedStr[l];
    }

    str[strlen(trimmedStr)] = '\0';

    return str;
}


int main(void) {
    char a[MAX_STRING_SIZE]= " ";
    char b[MAX_STRING_SIZE] = "asd";
    strcpy(a,b);
    puts(a);

    printf("\n");

    char fileName[MAX_STRING_SIZE]="mahmut.pty.d";
    char extension[MAX_STRING_SIZE]="bash";
    setFileExtension(fileName, extension);

    puts(fileName);

    printf("\n");

    char trmTest[MAX_STRING_SIZE] = "       sdadsadsa        ";

    puts(strTrim(trmTest));
    return 0;
}