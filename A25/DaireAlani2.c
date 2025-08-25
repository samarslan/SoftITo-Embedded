//
// Created by Samet Arslan on 25.08.2025.
//

#define PI 3.141592653589
#include <stdio.h>

void calcCircle(double *r) {
    *r = PI * (*r * *r);
}

int main() {
    double  r;

    scanf("%lf",&r);

    calcCircle(&r);

    printf("Area=%0.3f\n",r);
}
