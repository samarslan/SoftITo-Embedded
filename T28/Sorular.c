//
// Created by Samet Arslan on 28.07.2025.
//

#include <stdio.h>

void yvezYazdir(int x) {
    int y, z;
    if (x<0) {
        y = x*x + 2*x;
        z = 3*x;
    }
    else {
        y = x;
        z = x*x + 10;
    }
    printf("y=%d z=%d\n",y,z);
}

void abIliskisiniYazdir(int a, int b) {
    if (a>b) {
        printf("a>b");
    }
    else if (a<b) {
        printf("a<b");
    }
    else {
        printf("a=b");
    }
}

int sifirIleYuzArasindami(int x) {
    if (x>0) {
        if (x<100) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

int ucgenmi(int a, int b, int c) {
    if (a + b <= c) {
        return 0;
    }else if (a + c <= b) {
        return 0;
    }else if (b + c <= a) {
        return 0;
    }else {
        return 1;
    }
}

int eskenarMi(int a, int b, int c) {
    if (a == b) {
        if (b == c)
            return 1;
    }
    return 0;
}

int en_buyuk(int a, int b, int c) {
    int max;
    max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;
}

void harf_notu(int not) {
    if (not >= 90) {
        printf("AA\n");
        return;
    }
    if (not >= 80) {
        printf("AB\n");
        return;
    }
    if (not >= 70) {
        printf("BB\n");
        return;
    }
    if (not >= 60) {
        printf("\n");
        return;
    }
    if (not >= 55) {
        printf("CC\n");
        return;
    }
    if (not >= 50) {
        printf("DC\n");
        return;
    }
    else{
        printf("FF\n");
        return;
    }
}

int main() {
    int a, b, c, x, not;

    printf("Bir x değeri giriniz: ");
    scanf("%d", &x);
    yvezYazdir(x);

    printf("İki sayı giriniz (a ve b): ");
    scanf("%d %d", &a, &b);
    abIliskisiniYazdir(a, b);

    printf("Bir sayı giriniz (0-100 arasında mı kontrolü için): ");
    scanf("%d", &x);
    if (sifirIleYuzArasindami(x)) {
        printf("0 ile 100 arasında\n");
    } else {
        printf("0 ile 100 arasında değil\n");
    }

    printf("Üç kenar giriniz: ");
    scanf("%d %d %d", &a, &b, &c);
    if (ucgenmi(a, b, c)) {
        printf("Bu bir üçgendir\n");
        if (eskenarMi(a, b, c)) {
            printf("Eşkenar üçgendir\n");
        } else {
            printf("Eşkenar değildir\n");
        }
    } else {
        printf("Bu bir üçgen değildir\n");
    }

    printf("En büyük sayıyı bulmak için 3 sayı giriniz: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("En büyük: %d\n", en_buyuk(a, b, c));

    printf("Not giriniz: ");
    scanf("%d", &not);
    harf_notu(not);

    return 0;
}


