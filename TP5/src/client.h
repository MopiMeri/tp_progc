#ifndef CLIENT_H
#define CLIENT_H

#define SERVER_IP   "127.0.0.1"
#define SERVER_PORT 9090
#define MAX_MSG     1000

int connect_server(void);
int send_all(int sock, const char *buf, int len);
int recv_line(int sock, char *out, int max);

int envoie_operateur_numeros(int sock, char op, double a, int has_b, double b);

#endif
