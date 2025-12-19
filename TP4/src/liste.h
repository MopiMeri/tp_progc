#ifndef LISTE_H
#define LISTE_H

struct couleur {
    unsigned char r, g, b, a;
};

struct noeud {
    struct couleur c;
    struct noeud *suivant;
};

struct liste_couleurs {
    struct noeud *tete;
};

void init_liste(struct liste_couleurs *l);
void insertion(struct couleur *c, struct liste_couleurs *l);
void parcours(const struct liste_couleurs *l);
void liberer_liste(struct liste_couleurs *l);

#endif
