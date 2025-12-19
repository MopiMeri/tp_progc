#ifndef SERVEUR_H
#define SERVEUR_H

#define SERVER_PORT 9090
#define MAX_MSG     1000

int create_server_socket(void);
int send_all(int sock, const char *buf, int len);
int recv_line(int sock, char *out, int max);

int recois_numeros_calcule(const char *msg, char *op, double *a, int *has_b, double *b);

#endif
