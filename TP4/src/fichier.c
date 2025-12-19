#include "fichier.h"
#include <stdio.h>
#include <string.h>

void lire_fichier(const char *nom_de_fichier) {
    FILE *f = fopen(nom_de_fichier, "r");
    char ligne[512];

    if (!f) {
        printf("Erreur : impossible d'ouvrir %s en lecture.\n", nom_de_fichier);
        return;
    }

    while (fgets(ligne, sizeof(ligne), f)) {
        printf("%s", ligne);
    }

    fclose(f);
}

void ecrire_dans_fichier(const char *nom_de_fichier, const char *message) {
    FILE *f = fopen(nom_de_fichier, "a");
    if (!f) {
        printf("Erreur : impossible d'ouvrir %s en ecriture.\n", nom_de_fichier);
        return;
    }

    size_t n = strlen(message);
    if (n > 0 && message[n - 1] == '\n') {
        fputs(message, f);
    } else {
        fprintf(f, "%s\n", message);
    }

    fclose(f);
}
