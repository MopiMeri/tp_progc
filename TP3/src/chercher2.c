#include <stdio.h>

#define NB_PHRASES 10
#define TAILLE_PHRASE 200

int chaines_egales(const char *a, const char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0');
}

int main(void) {
    const char *phrases[NB_PHRASES] = {
        "Bonjour, comment ça va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journée.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent etre déroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est intéressante.",
        "Les structures de données sont importantes.",
        "Programmer en C, c'est génial."
    };

    char recherche[TAILLE_PHRASE];
    int trouve = 0;

    printf("Entrez la phrase a chercher :\n");
    if (fgets(recherche, TAILLE_PHRASE, stdin) == NULL) {
        return 1;
    }
    int i = 0;
    while (recherche[i] != '\0') {
        if (recherche[i] == '\n') {
            recherche[i] = '\0';
            break;
        }
        i++;
    }

    for (int j = 0; j < NB_PHRASES; j++) {
        if (chaines_egales(recherche, phrases[j])) {
            trouve = 1;
            break;
        }
    }

    if (trouve)
        printf("Phrase trouvée\n");
    else
        printf("Phrase non trouvée\n");

    return 0;
}
