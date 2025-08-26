//
// Created by Samet Arslan on 26.08.2025.
//

#ifndef SOFTITO_EMBEDDED_UTILITY_H
#define SOFTITO_EMBEDDED_UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

void printArray(const int *pa, int size);
void setRandomArray(int arr[], const int size);
int* createRandomArray(const int size);
int sumArray(const int *pa, int size);
unsigned int getBetterSeed();

#endif //SOFTITO_EMBEDDED_UTILITY_H