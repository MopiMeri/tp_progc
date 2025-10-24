#include <stdio.h>

int main() {
    int num1 = 5;
    int num2 = 4;
    char op = '*';
    int resultat;

    printf("=== Opérations avec switch ===\n");
    printf("num1 = %d, num2 = %d, opérateur = %c\n\n", num1, num2, op);

    switch (op) {
        case '+':
            resultat = num1 + num2;
            printf("%d + %d = %d\n", num1, num2, resultat);
            break;

        case '-':
            resultat = num1 - num2;
            printf("%d - %d = %d\n", num1, num2, resultat);
            break;

        case '*':
            resultat = num1 * num2;
            printf("%d * %d = %d\n", num1, num2, resultat);
            break;

        case '/':
            if (num2 != 0) {
                resultat = num1 / num2;
                printf("%d / %d = %d\n", num1, num2, resultat);
            } else {
                printf("Impossible, division par 0\n");
            }
            break;

        case '%':
            if (num2 != 0) {
                resultat = num1 % num2;
                printf("%d %% %d = %d\n", num1, num2, resultat);
            } else {
                printf("Impossible, modulo par 0\n");
            }
            break;

        case '&':
            resultat = num1 & num2;
            printf("%d & %d = %d (ET binaire)\n", num1, num2, resultat);
            break;

        case '|':
            resultat = num1 | num2;
            printf("%d | %d = %d (OU binaire)\n", num1, num2, resultat);
            break;

        case '~':
            printf("~%d = %d (NON binaire sur num1)\n", num1, ~num1);
            break;

        default:
            printf("Opérateur inconnu : %c\n", op);
            break;
    }

    return 0;
}



