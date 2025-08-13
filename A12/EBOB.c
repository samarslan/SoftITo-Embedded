//
// Created by Samet Arslan on 12.08.2025.
//

#include <stdio.h>

int ebob(int a, int b) {
    if (b == 0)
        return a;
    return ebob(b, a % b);
}

int main() {
    int x, y;
    printf("2 sayı girin: ");
    scanf("%d %d", &x, &y);

    printf("EBOB %d - %d = %d\n", x, y, ebob(x, y));
    return 0;
}