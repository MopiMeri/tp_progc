#include "serveur.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>

static volatile sig_atomic_t stop = 0;

static void handle_sigint(int sig) {
    (void)sig;
    stop = 1;
    printf("\nSignal Ctrl+C capture. Sortie du programme.\n");
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

int create_server_socket(void) {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) return -1;

    int opt = 1;
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVER_PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(s, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        close(s);
        return -1;
    }
    if (listen(s, 1) < 0) {
        close(s);
        return -1;
    }
    return s;
}


int recois_numeros_calcule(const char *msg, char *op, double *a, int *has_b, double *b) {
    char tmp[MAX_MSG];
    snprintf(tmp, sizeof(tmp), "%s", msg);

    size_t n = strlen(tmp);
    if (n > 0 && tmp[n-1] == '\n') tmp[n-1] = '\0';

    if (strncmp(tmp, "calcule :", 8) != 0) return -1;

    const char *p = tmp + 8;
    while (*p == ' ') p++;

    char op_local = 0;
    double x = 0.0, y = 0.0;

    if (sscanf(p, " %c %lf %lf", &op_local, &x, &y) == 3) {
        *op = op_local;
        *a = x;
        *b = y;
        *has_b = 1;
        return 0;
    }
    if (sscanf(p, " %c %lf", &op_local, &x) == 2) {
        *op = op_local;
        *a = x;
        *has_b = 0;
        return 0;
    }
    return -1;
}

static int calcule(char op, double a, int has_b, double b, double *out) {
    if (op == '~') {
        long long x = (long long)a;
        long long r = ~x;
        *out = (double)r;
        return 0;
    }
    if (!has_b) return -1;

    switch (op) {
        case '+': *out = a + b; return 0;
        case '-': *out = a - b; return 0;
        case '*': *out = a * b; return 0;
        case '/':
            if (b == 0.0) return -2;
            *out = a / b; return 0;
        case '%': {
            long long x = (long long)a;
            long long y = (long long)b;
            if (y == 0) return -2;
            *out = (double)(x % y);
            return 0;
        }
        case '&': {
            long long x = (long long)a;
            long long y = (long long)b;
            *out = (double)(x & y);
            return 0;
        }
        case '|': {
            long long x = (long long)a;
            long long y = (long long)b;
            *out = (double)(x | y);
            return 0;
        }
        default: return -3;
    }
}

int main(void) {
    signal(SIGINT, handle_sigint);

    int server = create_server_socket();
    if (server < 0) {
        printf("Erreur creation serveur\n");
        return 1;
    }

    printf("Serveur en attente de connexions...\n");

    struct sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);
    int client = accept(server, (struct sockaddr*)&client_addr, &len);
    if (client < 0) {
        close(server);
        return 1;
    }

    printf("Client connecte.\n");

    char buf[MAX_MSG];

    while (!stop) {
        int r = recv_line(client, buf, sizeof(buf));
        if (r <= 0) break;

        printf("Message recu: %s", buf);
