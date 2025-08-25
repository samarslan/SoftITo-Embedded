//
// Created by Samet Arslan on 25.08.2025.
//

#define PI 3.141592653589
#include <stdio.h>

void calcCircle(double r, double* area, double* perimeter) {
    *perimeter = 2 * PI * r ;
    *area = PI * (r * r);
}

int main() {
    double r;
    double area = 0;
    double perimeter = 0;
    scanf("%lf",&r);

    calcCircle(r, &area, &perimeter);

    printf("Perimeter = %0.3lf\n", perimeter);
    printf("Area = %0.3lf\n",area);
}
