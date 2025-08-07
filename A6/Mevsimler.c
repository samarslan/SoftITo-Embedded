//
// Created by Samet Arslan on 6.08.2025.
//

#include <stdio.h>

int main() {
    int month=0;
    printf("Please enter month:\n");
    scanf("%d", &month);

    switch (month) {
        case 12:
        case 1:
        case 2:
            printf("Winter");
            break;
        case 3:
        case 4:
        case 5:
            printf("Spring");
            break;
        case 6:
        case 7:
        case 8:
            printf("Summer");
            break;
        case 9:
        case 10:
        case 11:
            printf("Autumn");
            break;
    }

    return 0;
}
