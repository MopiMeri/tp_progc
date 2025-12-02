#include <stdio.h>

int main() {
    char s1[50] = "Hello";
    char s2[50] = " World!";
    char copie[50];
    char concat[100];

    int len = 0;
    while (s1[len] != '\0') len++;
    printf("Longueur : %d\n", len);

    int i = 0;
    while ((copie[i] = s1[i]) != '\0') i++;
    printf("Copie : %s\n", copie);

    i = 0;
    int j = 0;

    while ((concat[i] = s1[i]) != '\0') i++;

    while ((concat[i++] = s2[j++]) != '\0');

    printf("Concat : %s\n", concat);

    return 0;
}
