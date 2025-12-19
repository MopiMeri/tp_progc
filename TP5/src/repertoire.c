#include "repertoire.h"

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

static int est_dossier(const char *path) {
    struct stat st;
    if (stat(path, &st) != 0) return 0;
    return S_ISDIR(st.st_mode);
}

static void lire_dossier_rec_impl(const char *nom_repertoire, int depth) {
    DIR *dir = opendir(nom_repertoire);
    if (!dir) {
        printf("Erreur opendir('%s'): %s\n", nom_repertoire, strerror(errno));
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        const char *name = ent->d_name;

        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
            continue;

        for (int i = 0; i < depth; i++) printf("  ");
        printf("%s\n", name);

        char full[PATH_MAX];
        snprintf(full, sizeof(full), "%s/%s", nom_repertoire, name);

        if (est_dossier(full)) {
            lire_dossier_rec_impl(full, depth + 1);
        }
    }

    closedir(dir);
}

void lire_dossier(const char *nom_repertoire) {
    DIR *dir = opendir(nom_repertoire);
    if (!dir) {
        printf("Erreur opendir('%s'): %s\n", nom_repertoire, strerror(errno));
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        const char *name = ent->d_name;
        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
            continue;
        printf("%s\n", name);
    }

    closedir(dir);
}

void lire_dossier_recursif(const char *nom_repertoire) {
    lire_dossier_rec_impl(nom_repertoire, 0);
}

/*
 * Version itérative : on simule la récursivité avec une pile de chemins
 */
void lire_dossier_iteratif(const char *nom_repertoire) {
    // pile simple (tableau)
    char stack[1024][PATH_MAX];
    int top = 0;

    snprintf(stack[top++], PATH_MAX, "%s", nom_repertoire);

    while (top > 0) {
        char current[PATH_MAX];
        snprintf(current, sizeof(current), "%s", stack[--top]);

        DIR *dir = opendir(current);
        if (!dir) {
            printf("Erreur opendir('%s'): %s\n", current, strerror(errno));
            continue;
        }

        printf("\n[%s]\n", current);

        struct dirent *ent;
        while ((ent = readdir(dir)) != NULL) {
            const char *name = ent->d_name;
            if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
                continue;

            printf("%s\n", name);

            char full[PATH_MAX];
            snprintf(full, sizeof(full), "%s/%s", current, name);

            if (est_dossier(full)) {
                if (top < 1024) {
                    snprintf(stack[top++], PATH_MAX, "%s", full);
                } else {
                    printf("Pile pleine, dossier ignore: %s\n", full);
                }
            }
        }

        closedir(dir);
    }
}
