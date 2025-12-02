// TRI A BULLES

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

int main(void) {
    int tab[TAILLE];
    int i, j, tmp;

    srand(time(NULL));

    printf("Tableau non trie :\n");
    for (i = 0; i < TAILLE; i++) {
        tab[i] = (rand() % 201) - 100;
        printf("%d ", tab[i]);
    }
    printf("\n");

    for (i = 0; i < TAILLE - 1; i++) {
        for (j = 0; j < TAILLE - 1 - i; j++) {
            if (tab[j] > tab[j + 1]) {
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }

    printf("\nTableau trie par ordre croissant :\n");
    for (i = 0; i < TAILLE; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}
