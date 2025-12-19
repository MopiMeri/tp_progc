#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

void init_liste(struct liste_couleurs *l) {
    l->tete = NULL;
}

void insertion(struct couleur *c, struct liste_couleurs *l) {
    struct noeud *n = (struct noeud *)malloc(sizeof(struct noeud));
    if (!n) {
        printf("Erreur malloc\n");
        return;
    }
    n->c = *c;
    n->suivant = l->tete;
    l->tete = n;
}

void parcours(const struct liste_couleurs *l) {
    const struct noeud *tmp = l->tete;
    while (tmp) {
        printf("R:%3d G:%3d B:%3d A:%3d\n",
               tmp->c.r, tmp->c.g, tmp->c.b, tmp->c.a);
        tmp = tmp->suivant;
    }
}

void liberer_liste(struct liste_couleurs *l) {
    struct noeud *tmp = l->tete;
    while (tmp) {
        struct noeud *next = tmp->suivant;
        free(tmp);
        tmp = next;
    }
    l->tete = NULL;
}
