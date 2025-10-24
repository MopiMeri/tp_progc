#include <stdio.h>

int main() {
    char c = 'A';
    signed char sc = -65;
    unsigned char uc = 200;

    short s = -12345;
    unsigned short us = 54321;

    int i = -123456;
    unsigned int ui = 123456;

    long int li = -1234567890L;
    unsigned long int uli = 1234567890UL;

    long long int lli = -9876543210LL;
    unsigned long long int ulli = 9876543210ULL;

    float f = 3.14f;
    double d = 2.718281828;
    long double ld = 1.41421356237L;

    printf("=== Types de base et leurs valeurs ===\n\n");

    printf("char : %c\n", c);
    printf("signed char : %d\n", sc);
    printf("unsigned char : %u\n", uc);

    printf("\nshort : %d\n", s);
    printf("unsigned short : %u\n", us);

    printf("\nint : %d\n", i);
    printf("unsigned int : %u\n", ui);

    printf("\nlong int : %ld\n", li);
    printf("unsigned long int : %lu\n", uli);

    printf("\nlong long int : %lld\n", lli);
    printf("unsigned long long int : %llu\n", ulli);

    printf("\nfloat : %.2f\n", f);
    printf("double : %.6f\n", d);
    printf("long double : %.10Lf\n", ld);

    return 0;
}
