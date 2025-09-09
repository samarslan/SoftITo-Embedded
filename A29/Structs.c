//
// Created by Samet Arslan on 29.08.2025.
//

#include <stdio.h>
#include <math.h>

struct Date{
    int d;
    int m;
    int y;
};

struct Point {
    int x;
    int y;
};

void displayPointData(const struct Point *pnt) {
    printf("\nx=%d, y=%d\n", pnt->x, pnt->y);
}

void printPointsDataInArray(const struct Point pntArray[], size_t length) {
    for (size_t i=0; i<length; i++) {
        printf("\nx=%d, y=%d\n", (&(pntArray[i]))->x, pntArray[i].y);
    }
}

double getDistanceOf2Points(struct Point pnt1, struct Point pnt2) {
    double distance;

    distance = sqrt(
        pow((pnt2.x-pnt1.x),2)+
        pow((pnt2.y-pnt1.y),2));

    return distance;
}

int main() {
    struct Point p1;
    p1.x=20;
    p1.y=20;

    struct Point p2;
    p2.x=30;
    p2.y=40;

    struct Point pArray[2] = {p1,p2};

  //  printf("x=%d, y=%d", pArray[1].x, pArray[1].y);

    printf("\n");

    struct Point *ptr = &p1;


 //   printf("%f", getDistanceOf2Points(p1,p2));

 //   displayPointData(&p1);

    printPointsDataInArray(pArray, 2);

    return 0;
}