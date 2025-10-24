#include <stdio.h>

int main() {
    int compteur = 8;

    printf("=== Triangle rectangle avec des boucles for ===\n\n");

    for (int i = 1; i <= compteur; i++) {
        for (int j = 1; j <= i; j++) {
            if (i % 2 == 0 && j % 2 == 0)
                printf("# ");
            else
                printf("* ");
        }
        printf("\n");
    }

    return 0;
}

