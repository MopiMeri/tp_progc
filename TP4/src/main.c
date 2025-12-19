#include <stdio.h>
#include <string.h>

#include "operator.h"
#include "fichier.h"
#include "liste.h"

static void strip_newline(char *s) {
    if (!s) return;
    size_t n = strlen(s);
    if (n > 0 && s[n - 1] == '\n') s[n - 1] = '\0';
}

static void exercice41(void) {
    int a, b;
    char op;

    printf("Entrez num1 : ");
    scanf("%d", &a);

    printf("Entrez num2 : ");
    scanf("%d", &b);

    printf("Entrez l'operateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op);

    switch (op) {
        case '+': printf("Resultat : %d\n", somme(a, b)); break;
        case '-': printf("Resultat : %d\n", difference(a, b)); break;
        case '*': printf("Resultat : %d\n", produit(a, b)); break;
        case '/':
            if (b == 0) printf("Erreur: division par 0\n");
            else printf("Resultat : %d\n", quotient(a, b));
            break;
        case '%':
            if (b == 0) printf("Erreur: modulo par 0\n");
            else printf("Resultat : %d\n", modulo(a, b));
            break;
        case '&': printf("Resultat : %d\n", et(a, b)); break;
        case '|': printf("Resultat : %d\n", ou(a, b)); break;
        case '~': printf("Resultat : %d\n", negation(a)); break;
        default:  printf("Operateur invalide\n");
    }
}

static void exercice42(void) {
    int choix;
    char nom[256];
    char message[1024];

    printf("Que souhaitez-vous faire ?\n");
    printf("1. Lire un fichier\n");
    printf("2. Ecrire dans un fichier\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    getchar();

    printf("Entrez le nom du fichier : ");
    if (!fgets(nom, sizeof(nom), stdin)) return;
    strip_newline(nom);

    if (choix == 1) {
        printf("\nContenu du fichier %s :\n", nom);
        lire_fichier(nom);
    } else if (choix == 2) {
        printf("Entrez le message a ecrire : ");
        if (!fgets(message, sizeof(message), stdin)) return;
        ecrire_dans_fichier(nom, message);
        printf("Le message a ete ecrit dans le fichier %s.\n", nom);
    } else {
        printf("Choix invalide\n");
    }
}

static void exercice47(void) {
    struct liste_couleurs ma_liste;
    init_liste(&ma_liste);

    struct couleur couleurs[10] = {
        {0xFF, 0x00, 0x00, 0xFF}, 
        {0x00, 0xFF, 0x00, 0xFF},
        {0x00, 0x00, 0xFF, 0xFF},
        {0xFF, 0xFF, 0x00, 0xFF}, 
        {0xFF, 0x00, 0xFF, 0xFF},
        {0x00, 0xFF, 0xFF, 0xFF},
        {0x80, 0x80, 0x80, 0xFF},
        {0xFF, 0xA5, 0x00, 0xFF}, 
        {0x4B, 0x00, 0x82, 0xFF},
        {0x00, 0x00, 0x00, 0xFF} 
    };

    for (int i = 0; i < 10; i++) {
        insertion(&couleurs[i], &ma_liste);
    }

    printf("Liste des couleurs (RGBA) :\n");
    parcours(&ma_liste);

    liberer_liste(&ma_liste);
}

int main(void) {
    int choix;

    printf("Choisissez un exercice :\n");
    printf("1 - Exercice 4.1 (Calcul avec operateurs)\n");
    printf("2 - Exercice 4.2 (Gestion de fichiers)\n");
    printf("3 - Exercice 4.7 (Liste de couleurs)\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1: exercice41(); break;
        case 2: exercice42(); break;
        case 3: exercice47(); break;
        default: printf("Choix invalide\n");
    }

    return 0;
}
