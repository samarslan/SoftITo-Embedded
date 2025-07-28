//
// Created by Samet Arslan on 28.07.2025.
//

#include <stdio.h>

void ornek1() {
    int i;
    for (i = 1; i <= 100; i++) {
        if (i % 3 == 0 || i % 4 == 0 || i % 5 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void ornek2() {
    int i = 3;
    while (i <= 100) {
        printf("%d ", i);
        if (i % 3 == 0) {
            i += 1;
        } else if (i % 5 == 0) {
            i += 2;
        } else {
            i += 3;
        }
    }
    printf("\n");
}

void ornek3(int a, int b) {
    int i;
    for (i = a + 1; i < b; i++) {
        if (i % 5 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void ornek4() {
    int f;
    for (f = 10; f <= 90; f += 4) {
        float c = 5.0 / 9 * (f - 32);
        printf("F: %d -> C: %.2f\n", f, c);
    }
}

int ornek5(int n) {
    int i, toplam = 0;
    for (i = 1; i <= n; i++) {
        toplam += i;
    }
    return toplam;
}

int ornek6() {
    int i, sayi, toplam = 0;
    for (i = 1; i <= 8; i++) {
        printf("%d. sayıyı girin: ", i);
        scanf("%d", &sayi);
        toplam += sayi;
    }
    return toplam;
}

int main() {
    int a, b, n;

    printf("Örnek 1:\n");
    ornek1();

    printf("Örnek 2:\n");
    ornek2();

    printf("Örnek 3 (a ve b giriniz): ");
    scanf("%d %d", &a, &b);
    ornek3(a, b);

    printf("Örnek 4:\n");
    ornek4();

    printf("Örnek 5 (n giriniz): ");
    scanf("%d", &n);
    printf("Toplam: %d\n", ornek5(n));

    printf("Örnek 6:\n");
    printf("Toplam: %d\n", ornek6());

    return 0;
}
