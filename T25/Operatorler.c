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
  //  int ival= 0b10110110101;

 //   int result = f1()+f2()*5;

    int day, hour, min, sec;
    scanf("%d%d%d%d", &day, &hour, &min, &sec);
    min = min + sec/60;
    sec = sec % 60;
    hour = hour + min/60;
    min = min % 60;
    day = day + hour/24;
    hour = hour % 24;
    printf("%d\n%d\n%d\n%d", day, hour, min, sec);
}
