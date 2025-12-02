#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Couleur;

typedef struct {
    Couleur c;
    int occurrences;
} CouleurComptee;

int couleurs_egales(Couleur c1, Couleur c2) {
    return c1.r == c2.r &&
           c1.g == c2.g &&
           c1.b == c2.b &&
           c1.a == c2.a;
}

int main(void) {
    Couleur tab[N];
    CouleurComptee distinctes[N];
    int nb_distinctes = 0;

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        tab[i].a = rand() % 256;
        tab[i].r = rand() % 256;
        tab[i].g = rand() % 256;
        tab[i].b = rand() % 256;
    }

    for (int i = 0; i < N; i++) {
        int trouve = 0;

        for (int j = 0; j < nb_distinctes; j++) {
            if (couleurs_egales(tab[i], distinctes[j].c)) {
                distinctes[j].occurrences++;
                trouve = 1;
                break;
            }
        }

        if (!trouve) {
            distinctes[nb_distinctes].c = tab[i];
            distinctes[nb_distinctes].occurrences = 1;
            nb_distinctes++;
        }
    }

    for (int j = 0; j < nb_distinctes; j++) {
        printf("%02x 0x%02x 0x%02x 0x%02x : %d\n",
               distinctes[j].c.a,
               distinctes[j].c.r,
               distinctes[j].c.g,
               distinctes[j].c.b,
               distinctes[j].occurrences);
    }

    return 0;
}
