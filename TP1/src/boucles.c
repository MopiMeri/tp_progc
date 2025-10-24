#include <stdio.h>

int main() {
    int compteur = 8;

    if (compteur >= 10) {
        printf("Erreur : compteur doit être inférieur à 10.\n");
        return 1;
    }

    printf("=== Triangle rectangle avec des boucles for ===\n\n");

    for (int i = 1; i <= compteur; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == compteur)
                printf("* ");
            else
                printf("# ");
        }
        printf("\n");
    }

    return 0;
}
