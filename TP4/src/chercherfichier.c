#include <stdio.h>
#include <string.h>

static int count_occurrences(const char *ligne, const char *mot) {
    int count = 0;
    size_t m = strlen(mot);
    if (m == 0) return 0;

    const char *p = ligne;
    while ((p = strstr(p, mot)) != NULL) {
        count++;
        p += m; 
    }
    return count;
}

static void strip_newline(char *s) {
    if (!s) return;
    size_t n = strlen(s);
    if (n > 0 && s[n - 1] == '\n') s[n - 1] = '\0';
}

int main(void) {
    char nom[256];
    char phrase[256];
    char ligne[1024];

    printf("Entrez le nom du fichier : ");
    if (!fgets(nom, sizeof(nom), stdin)) return 1;
    strip_newline(nom);

    printf("Entrez la phrase que vous souhaitez rechercher : ");
    if (!fgets(phrase, sizeof(phrase), stdin)) return 1;
    strip_newline(phrase);

    FILE *f = fopen(nom, "r");
    if (!f) {
        printf("Erreur : impossible d'ouvrir %s\n", nom);
        return 1;
    }

    int num_ligne = 0;
    int trouve = 0;

    printf("\nResultats de la recherche :\n");

    while (fgets(ligne, sizeof(ligne), f)) {
        num_ligne++;
        int c = count_occurrences(ligne, phrase);
        if (c > 0) {
            printf("Ligne %d, %d fois\n", num_ligne, c);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucune occurrence trouvee.\n");
    }

    fclose(f);
    return 0;
}
