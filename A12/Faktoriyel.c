//
// Created by Samet Arslan on 12.08.2025.
//

#include <stdio.h>

long Faktoryel(int x) {
    if (x <= 1) {
        return 1;
    }
    return x * Faktoryel(x - 1);
}


int main(){
    int sayi=1;


    printf("Sayı girin: ");
    scanf("%d", &sayi);


    printf("\n%ld\n", Faktoryel(sayi));
}