#include <stdio.h>

int main() {
    int nombres[] = {0, 4096, 65536, 65535, 1024};
    int taille = sizeof(nombres) / sizeof(nombres[0]);

    printf("=== Affichage d'un nombre en format binaire ===\n\n");

    for (int n = 0; n < taille; n++) {
        int nombre = nombres[n];

        printf("Nombre : %d\nBinaire : ", nombre);

        for (int i = 31; i >= 0; i--) {
            int bit = (nombre >> i) & 1;  
            printf("%d", bit);
            if (i % 4 == 0)
                printf(" ");
        }
        printf("\n\n");
    }
    return 0;
}
