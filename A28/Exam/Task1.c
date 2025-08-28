#include <stdio.h>



int main(void) {
    unsigned int a=163;

    a ^= (1u<<4);
    a ^= (1u<<3);
    a ^= (1u<<2);
    a ^= (1u<<1);
    a ^= (1u<<0);

    printf("%u", a);
    return 0;
}