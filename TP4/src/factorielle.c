#include <stdio.h>

int factorielle(int num) {
    if (num == 0) {
        printf("fact(0): 1\n");
        return 1;
    } else {
        int valeur = num * factorielle(num - 1);
        printf("fact(%d): %d\n", num, valeur);
        return valeur;
    }
}

int main(void) {
    int n;

    printf("Entrez un entier naturel (0..12 conseille pour int) : ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Erreur: n doit etre >= 0\n");
        return 1;
    }

    int res = factorielle(n);
    printf("Factorielle(%d) = %d\n", n, res);
    return 0;
}
