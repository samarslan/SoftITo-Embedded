#include <stdio.h>

void birdenYuzeSayilariYazdir() {
    int i = 1;
    while (i <= 100) {
        printf("%d ", i);
        i++;
    }
    printf("\n");
}

void yuzdenKucukTekSayilariYazdir() {
    int i = 1;
    while (i < 100) {
        if (i % 2 == 1) {
            printf("%d ", i);
        }
        i++;
    }
    printf("\n");
}

void yuzdenKucukTekSayilariYazdir2() {
    int i = 1;
    while (i < 100) {
        printf("%d ", i);
        i += 2;
    }
    printf("\n");
}

void yuzdenGeriyeYazdir() {
    int i = 100;
    while (i >= 50) {
        printf("%d ", i);
        i--;
    }
    printf("\n");
}

void basilanSayidanGeriyeYazdir(int n) {
    int i = 1;
    while (i <= n) {
        printf("%d ", i);
        i++;
    }
    printf("\n");
}

void aralarindaYazdir(int a, int b) {
    if (a < b) {
        while (a <= b) {
            printf("%d ", a);
            a++;
        }
    } else if (a > b) {
        while (a >= b) {
            printf("%d ", a);
            a--;
        }
    } else {
        printf("%d", a);
    }
    printf("\n");
}

void ornek7(int n) {
    int i;
    if (n % 2 == 0) {
        i = 0;
        while (i <= n) {
            printf("%d ", i);
            i += 2;
        }
    } else {
        i = 1;
        while (i <= n) {
            printf("%d ", i);
            i += 2;
        }
    }
    printf("\n");
}

int main() {
    int n, a, b;

    printf("Ornek 1:\n");
    birdenYuzeSayilariYazdir();

    printf("Ornek 2:\n");
    yuzdenKucukTekSayilariYazdir();

    printf("Ornek 3:\n");
    yuzdenKucukTekSayilariYazdir2();

    printf("Ornek 4:\n");
    yuzdenGeriyeYazdir();

    printf("Ornek 5 - n giriniz: ");
    scanf("%d", &n);
    basilanSayidanGeriyeYazdir(n);

    printf("Ornek 6 - a ve b giriniz: ");
    scanf("%d %d", &a, &b);
    aralarindaYazdir(a, b);

    printf("Ornek 7 - n giriniz: ");
    scanf("%d", &n);
    ornek7(n);

    return 0;
}
