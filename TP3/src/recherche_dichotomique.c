#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

int main(void) {
    int tab[TAILLE];
    int i;
    int gauche, droite, milieu;
    int cible;
    int trouve = 0;

    srand(time(NULL));

    for (i = 0; i < TAILLE; i++) {
        tab[i] = i * 2;
    }

    printf("Tableau trié :\n");
    for (i = 0; i < TAILLE; i++) {
        printf("%d ", tab[i]);
    }

    printf("\n\nEntrez l'entier que vous souhaitez chercher : ");
    scanf("%d", &cible);

    gauche = 0;
    droite = TAILLE - 1;

    printf("\n=== Début de la recherche dichotomique ===\n");

    while (gauche <= droite) {

        milieu = (gauche + droite) / 2;

        printf("\nIntervalle indices : gauche = %d, milieu = %d, droite = %d\n",
               gauche, milieu, droite);

        printf("Intervalle valeurs : [ %d ... %d ... %d ]\n",
               tab[gauche], tab[milieu], tab[droite]);

        if (tab[milieu] == cible) {
            printf("==> %d == %d → valeur trouvée au milieu !\n", tab[milieu], cible);
            trouve = 1;
            break;
        }
        else if (tab[milieu] < cible) {
            printf("→ %d est plus petit que %d → on garde la PARTIE DROITE\n",
                   tab[milieu], cible);
            gauche = milieu + 1;
        }
        else {
            printf("→ %d est plus grand que %d → on garde la PARTIE GAUCHE\n",
                   tab[milieu], cible);
            droite = milieu - 1;
        }
    }

    if (trouve)
        printf("\nRésultat final : entier présent dans le tableau.\n");
    else
        printf("\nRésultat final : entier absent du tableau.\n");

    return 0;
}
