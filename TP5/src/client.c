#include "client.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

static void strip_newline(char *s) {
    size_t n = strlen(s);
    if (n > 0 && s[n-1] == '\n') s[n-1] = '\0';
}

int send_all(int sock, const char *buf, int len) {
    int sent = 0;
    while (sent < len) {
        int n = (int)send(sock, buf + sent, len - sent, 0);
        if (n <= 0) return -1;
        sent += n;
    }
    return 0;
}

int recv_line(int sock, char *out, int max) {
    int i = 0;
    while (i < max - 1) {
        char c;
        int n = (int)recv(sock, &c, 1, 0);
        if (n <= 0) return -1;
        out[i++] = c;
        if (c == '\n') break;
    }
    out[i] = '\0';
    return i;
}

int connect_server(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) return -1;

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        close(sock);
        return -1;
    }
    return sock;
}

int envoie_operateur_numeros(int sock, char op, double a, int has_b, double b) {
    char msg[MAX_MSG];

    if (op == '~') {
        snprintf(msg, sizeof(msg), "calcule : ~ %.10g\n", a);
    } else {
        if (!has_b) return -1;
        snprintf(msg, sizeof(msg), "calcule : %c %.10g %.10g\n", op, a, b);
    }
    return send_all(sock, msg, (int)strlen(msg));
}

static int read_note_file(const char *path, double *out) {
    FILE *f = fopen(path, "r");
    if (!f) return -1;
    if (fscanf(f, "%lf", out) != 1) { fclose(f); return -1; }
    fclose(f);
    return 0;
}

static void ex56_notes_mode(int sock) {
    const char *candidates[5][3] = {
        {"etudiant/1.txt", "etudiant/note1.txt", "etudiant/etudiant1.txt"},
        {"etudiant/2.txt", "etudiant/note2.txt", "etudiant/etudiant2.txt"},
        {"etudiant/3.txt", "etudiant/note3.txt", "etudiant/etudiant3.txt"},
        {"etudiant/4.txt", "etudiant/note4.txt", "etudiant/etudiant4.txt"},
        {"etudiant/5.txt", "etudiant/note5.txt", "etudiant/etudiant5.txt"}
    };

    double notes[5];
    for (int i = 0; i < 5; i++) {
        int ok = -1;
        for (int j = 0; j < 3; j++) {
            if (read_note_file(candidates[i][j], &notes[i]) == 0) {
                ok = 0;
                break;
            }
        }
        if (ok != 0) {
            printf("Impossible de lire une note pour l'etudiant %d (dossier ./etudiant manquant ou format invalide)\n", i+1);
            return;
        }
    }

    char line[MAX_MSG];

    envoie_operateur_numeros(sock, '+', notes[0], 1, notes[1]);
    if (recv_line(sock, line, sizeof(line)) < 0) return;
    double somme;
    if (sscanf(line, "calcule : %lf", &somme) != 1) {
        printf("Reponse serveur invalide: %s", line);
        return;
    }

    for (int i = 2; i < 5; i++) {
        envoie_operateur_numeros(sock, '+', somme, 1, notes[i]);
        if (recv_line(sock, line, sizeof(line)) < 0) return;
        if (sscanf(line, "calcule : %lf", &somme) != 1) {
            printf("Reponse serveur invalide: %s", line);
            return;
        }
    }

    envoie_operateur_numeros(sock, '/', somme, 1, 5.0);
    if (recv_line(sock, line, sizeof(line)) < 0) return;
    double moyenne;
    if (sscanf(line, "calcule : %lf", &moyenne) != 1) {
        printf("Reponse serveur invalide: %s", line);
        return;
    }

    printf("\nNotes lues:\n");
    for (int i = 0; i < 5; i++) printf(" - note%d = %.2f\n", i+1, notes[i]);
    printf("Somme = %.2f\n", somme);
    printf("Moyenne = %.2f\n", moyenne);
}

int main(void) {
    int sock = connect_server();
    if (sock < 0) {
        printf("Connexion au serveur impossible (lancer ./serveur d'abord)\n");
        return 1;
    }

    printf("Connecte au serveur.\n");
    printf("Commandes:\n");
    printf(" - message libre (Ex 5.4)\n");
    printf(" - calcule : <op> <a> <b>   ex: calcule : + 23 45\n");
    printf(" - calcule : ~ <a>\n");
    printf(" - ex56 (calcule somme/moyenne depuis ./etudiant)\n");
    printf(" - quit\n\n");

    char input[MAX_MSG];
    char reply[MAX_MSG];

    while (1) {
        printf("> ");
        if (!fgets(input, sizeof(input), stdin)) break;
        strip_newline(input);

        if (strcmp(input, "quit") == 0) break;

        if (strcmp(input, "ex56") == 0) {
            ex56_notes_mode(sock);
            continue;
        }

        if (strncmp(input, "calcule :", 8) == 0) {
            char msg[MAX_MSG];
            snprintf(msg, sizeof(msg), "%s\n", input);
            if (send_all(sock, msg, (int)strlen(msg)) < 0) break;

            if (recv_line(sock, reply, sizeof(reply)) < 0) break;
            printf("%s", reply);
            continue;
        }

        char msg[MAX_MSG];
        snprintf(msg, sizeof(msg), "message : %s\n", input);
        if (send_all(sock, msg, (int)strlen(msg)) < 0) break;

        if (recv_line(sock, reply, sizeof(reply)) < 0) break;
        printf("%s", reply);
    }

    close(sock);
    printf("Client termine.\n");
    return 0;
}
