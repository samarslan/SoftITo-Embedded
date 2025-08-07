//
// Created by Samet Arslan on 6.08.2025.
//

#include <stdio.h>

void DisplayData(int day, int month, int year) {
     char* monthNames[] = {"January",     "February",    "March",
                         "April",       "May",         "June",
                        "July",        "August",      "September",
                        "October",     "November",    "December"
    };

    if (day>=11&&day<=13) {
        printf("%dth ", day);
    }else{
        switch (day%10) {
            case 1:
                printf("%dst ", day);
                break;
            case 2:
                printf("%dnd ", day);
                break;
            case 3:
                printf("%drd ", day);
                break;
            default:
                printf("%dth ", day);
                break;
        }
    }
    printf("%s %d\n", monthNames[month], year);
}

int main() {
    int day=0;
    int month=0;
    int year=0;
    printf("Enter day: \n");
    scanf("%d", &day);
    printf("Enter month: \n");
    scanf("%d", &month);
    printf("Enter year: \n");
    scanf("%d", &year);
    DisplayData(day, month, year);
    // DisplayData(23, 2, 2006);
    return 0;
}