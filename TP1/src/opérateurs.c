#include <stdio.h>

int main() {
    int a = 16;
    int b = 3;

    printf("=== Opérateurs arithmétiques et logiques ===\n\n");
    printf("a = %d, b = %d\n\n", a, b);

    printf("Addition (a + b) = %d\n", a + b);
    printf("Soustraction (a - b) = %d\n", a - b);
    printf("Multiplication (a * b) = %d\n", a * b);
    printf("Division entière (a / b) = %d\n", a / b);
    printf("Modulo (a %% b) = %d\n", a % b); 
    printf("\n=== Comparaisons ===\n");
    printf("a == b : %d\n", a == b);
    printf("a > b  : %d\n", a > b);
    printf("a < b  : %d\n", a < b);
    printf("a != b : %d\n", a != b);
    printf("a >= b : %d\n", a >= b);
    printf("a <= b : %d\n", a <= b);

    printf("\n=== Opérateurs logiques ===\n");
    printf("(a > 0) && (b > 0) : %d\n", (a > 0) && (b > 0)); // ET logique
    printf("(a > 0) || (b < 0) : %d\n", (a > 0) || (b < 0)); // OU logique
    printf("!(a == b)          : %d\n", !(a == b));          // NON logique

    return 0;
}
