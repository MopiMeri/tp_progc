#include <stdio.h>
#include <stdlib.h>

#include "operator.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage:\n");
        printf("  %s <op> <num1> <num2>\n", argv[0]);
        printf("  %s ~ <num>\n", argv[0]);
        return 1;
    }

    char op = argv[1][0];

    if (op == '~') {
        if (argc != 3) {
            printf("Usage: %s ~ <num>\n", argv[0]);
            return 1;
        }
        int a = atoi(argv[2]);
        printf("Resultat : %d\n", negation(a));
        return 0;
    }

    if (argc != 4) {
        printf("Usage: %s <op> <num1> <num2>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[2]);
    int b = atoi(argv[3]);

    switch (op) {
        case '+': printf("Resultat : %d\n", somme(a, b)); break;
        case '-': printf("Resultat : %d\n", difference(a, b)); break;
        case '*': printf("Resultat : %d\n", produit(a, b)); break;
        case '/':
            if (b == 0) { printf("Erreur: division par 0\n"); return 1; }
            printf("Resultat : %d\n", quotient(a, b));
            break;
        case '%':
            if (b == 0) { printf("Erreur: modulo par 0\n"); return 1; }
            printf("Resultat : %d\n", modulo(a, b));
            break;
        case '&': printf("Resultat : %d\n", et(a, b)); break;
        case '|': printf("Resultat : %d\n", ou(a, b)); break;
        default:
            printf("Operateur invalide: %c\n", op);
            return 1;
    }

    return 0;
}
