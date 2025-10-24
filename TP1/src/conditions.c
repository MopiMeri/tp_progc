#include <stdio.h>

int main() {
    int somme = 0;

    for (int i = 1; i <= 1000; i++) {

        if (i % 11 == 0) {
            continue;
        }

        if (i % 5 == 0 || i % 7 == 0) {
            somme += i;
        }

        if (somme > 5000) {
            printf("La somme a dépassé 5000 à i = %d\n", i);
            break;
        }
    }

    printf("Somme finale : %d\n", somme);

    return 0;
}
