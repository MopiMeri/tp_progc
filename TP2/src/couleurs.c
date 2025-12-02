#include <stdio.h>

struct Couleur {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

int main() {
    struct Couleur couleurs[10] = {
        {0xef, 0x78, 0x12, 0xff},
        {0x2c, 0xc8, 0x64, 0xff},
        {0xaa, 0x11, 0x22, 0xff},
        {0x45, 0x88, 0x99, 0xff},
        {0x10, 0x20, 0x30, 0xff},
        {0xfe, 0xee, 0xdd, 0xff},
        {0x99, 0x77, 0x55, 0xff},
        {0x01, 0x02, 0x03, 0xff},
        {0xab, 0xcd, 0xef, 0xff},
        {0x00, 0xff, 0x00, 0xff}
    };

    for (int i = 0; i < 10; i++) {
        printf("Couleur %d :\n", i + 1);
        printf("Rouge : %u\n", couleurs[i].r);
        printf("Vert : %u\n", couleurs[i].g);
        printf("Bleu : %u\n", couleurs[i].b);
        printf("Alpha : %u\n\n", couleurs[i].a);
    }

    return 0;
}
