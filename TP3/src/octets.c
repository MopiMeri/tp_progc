#include <stdio.h>

void afficher_octets(void *p, size_t taille) {
    unsigned char *c = (unsigned char *)p;
    for (size_t i = 0; i < taille; i++) {
        printf("%02x ", c[i]);
    }
    printf("\n");
}

int main(void) {
    short s = 0x0302;
    int i = 0x04030201;
    long int li = 0x0807060504030201L;
    float f = 5.0f;
    double d = 1.0;
    long double ld = 1.0L;

    printf("Octets de short :\n");
    afficher_octets(&s, sizeof(short));

    printf("\nOctets de int :\n");
    afficher_octets(&i, sizeof(int));

    printf("\nOctets de long int :\n");
    afficher_octets(&li, sizeof(long int));

    printf("\nOctets de float :\n");
    afficher_octets(&f, sizeof(float));

    printf("\nOctets de double :\n");
    afficher_octets(&d, sizeof(double));

    printf("\nOctets de long double :\n");
    afficher_octets(&ld, sizeof(long double));

    return 0;
}
