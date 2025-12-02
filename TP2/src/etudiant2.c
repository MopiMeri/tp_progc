#include <stdio.h>
#include <string.h>

struct Etudiant {
    char nom[30];
    char prenom[30];
    char adresse[50];
    float noteC;
    float noteSE;
};

int main() {

    struct Etudiant etu[5];

    strcpy(etu[0].nom, "Etudiant1_Nom");
    strcpy(etu[0].prenom, "Etudiant1_Prénom");
    strcpy(etu[0].adresse, "Etudiant1_Adresse");
    etu[0].noteC = 10.0;
    etu[0].noteSE = 14.0;

    strcpy(etu[1].nom, "Etudiant2_Nom");
    strcpy(etu[1].prenom, "Etudiant2_Prénom");
    strcpy(etu[1].adresse, "Etudiant2_Adresse");
    etu[1].noteC = 11.0;
    etu[1].noteSE = 13.0;

    strcpy(etu[2].nom, "Etudiant3_Nom");
    strcpy(etu[2].prenom, "Etudiant3_Prénom");
    strcpy(etu[2].adresse, "Etudiant3_Adresse");
    etu[2].noteC = 12.0;
    etu[2].noteSE = 12.0;

    strcpy(etu[3].nom, "Etudiant4_Nom");
    strcpy(etu[3].prenom, "Etudiant4_Prénom");
    strcpy(etu[3].adresse, "Etudiant4_Adresse");
    etu[3].noteC = 13.0;
    etu[3].noteSE = 11.0;

    strcpy(etu[4].nom, "Etudiant5_Nom");
    strcpy(etu[4].prenom, "Etudiant5_Prénom");
    strcpy(etu[4].adresse, "Etudiant5_Adresse");
    etu[4].noteC = 14.0;
    etu[4].noteSE = 10.0;


    for (int i = 0; i < 5; i++) {
        printf("Etudiant %d :\n", i + 1);
        printf("Nom : %s\n", etu[i].nom);
        printf("Prenom : %s\n", etu[i].prenom);
        printf("Adresse : %s\n", etu[i].adresse);
        printf("Note C : %.2f\n", etu[i].noteC);
        printf("Note SE : %.2f\n\n", etu[i].noteSE);
    }

    return 0;
}
