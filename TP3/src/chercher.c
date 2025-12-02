#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

int main(void) {
    int tab[TAILLE];
    int i, cible;
    int trouve = 0;

    srand(time(NULL));

    printf("Tableau :\n");
    for (i = 0; i < TAILLE; i++) {
        tab[i] = (rand() % 201) - 100;
        printf("%d ", tab[i]);
    }
    printf("\n\nEntrez l'entier que vous souhaitez chercher : ");
    scanf("%d", &cible);

    for (i = 0; i < TAILLE; i++) {
        if (tab[i] == cible) {
            trouve = 1;
            break;
        }
    }

    if (trouve)
        printf("\nResultat : entier present\n");
    else
        printf("\nResultat : entier absent\n");

    return 0;
}
