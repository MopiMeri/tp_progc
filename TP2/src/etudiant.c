#include <stdio.h>

int main() {
    char noms[5][30] = {"Etudiant1_Nom", "Etudiant2_Nom", "Etudiant3_Nom", "Etudiant4_Nom", "Etudiant5_Nom"};
    char prenoms[5][30] = {"Etudiant1_Prénom", "Etudiant2_Prénom", "Etudiant3_Prénom", "Etudiant4_Prénom", "Etudiant5_Prénom"};
    char adresses[5][50] = {
        "Etudiant1_Adresse",
        "Etudiant2_Adresse",
        "Etudiant3_Adresse",
        "Etudiant4_Adresse",
        "Etudiant5_Adresse"
    };

    float noteC[5] = {10.0, 11.0, 12.0, 13.0, 14.0};
    float noteSE[5] = {14.0, 13.0, 12.0, 11.0, 10.0};

    for (int i = 0; i < 5; i++) {
        printf("Etudiant %d :\n", i+1);
        printf("Nom : %s\n", noms[i]);
        printf("Prenom : %s\n", prenoms[i]);
        printf("Adresse : %s\n", adresses[i]);
        printf("Note C : %.2f\n", noteC[i]);
        printf("Note SE : %.2f\n\n", noteSE[i]);
    }

    return 0;
}
