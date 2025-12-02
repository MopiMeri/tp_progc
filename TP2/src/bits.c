#include <stdio.h>

int main() {
    unsigned int d = 0x10001000;

    int bit4  = (d >> (32 - 4)) & 1; 
    int bit20 = (d >> (32 - 20)) & 1;

    printf("bit4 = %d, bit20 = %d\n", bit4, bit20);

    if (bit4 == 1 && bit20 == 1)
        printf("1\n");
    else
        printf("0\n");

    return 0;
}
