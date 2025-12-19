#include <stdio.h>
#include <string.h>

#include "fichier.h"

#define N 5

struct etudiant {
    char nom[64];
    char prenom[64];
    char adresse[128];
    int note1;
    int note2;
};

static void strip_newline(char *s) {
    if (!s) return;
    size_t n = strlen(s);
    if (n > 0 && s[n - 1] == '\n') s[n - 1] = '\0';
}

static void read_line(const char *prompt, char *buf, size_t sz) {
    printf("%s", prompt);
    if (fgets(buf, sz, stdin)) {
        strip_newline(buf);
    } else {
        buf[0] = '\0';
    }
}

int main(void) {
    struct etudiant tab[N];

    FILE *clear = fopen("etudiant.txt", "w");
    if (clear) fclose(clear);

    for (int i = 0; i < N; i++) {
        printf("\nEntrez les details de l'etudiant.e %d :\n", i + 1);

        read_line("Nom : ", tab[i].nom, sizeof(tab[i].nom));
        read_line("Prenom : ", tab[i].prenom, sizeof(tab[i].prenom));
        read_line("Adresse : ", tab[i].adresse, sizeof(tab[i].adresse));

        printf("Note 1 : ");
        scanf("%d", &tab[i].note1);
        printf("Note 2 : ");
        scanf("%d", &tab[i].note2);
        getchar(); // consomme '\n'

        char ligne[512];
        snprintf(ligne, sizeof(ligne), "%s;%s;%s;%d;%d",
                 tab[i].nom, tab[i].prenom, tab[i].adresse,
                 tab[i].note1, tab[i].note2);

        ecrire_dans_fichier("etudiant.txt", ligne);
    }

    printf("\nLes details des etudiants ont ete enregistres dans etudiant.txt.\n");
    printf("Contenu actuel :\n");
    lire_fichier("etudiant.txt");

    return 0;
}
