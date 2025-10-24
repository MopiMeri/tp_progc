#include <stdio.h>

int main() {
    int n = 5; 

    printf("=== Pyramide de nombres ===\n\n");

    for (int i = 1; i <= n; i++) {
        for (int espace = 1; espace <= n - i; espace++) {
            printf(" ");
        }

        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }

        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }
    printf("\nPyramide terminée !\n");
    return 0;
}
