CC=gcc
CFLAGS=-Wall -Wextra -O2

all: repertoire client serveur

repertoire: repertoire_main.o repertoire.o
	$(CC) $(CFLAGS) -o repertoire repertoire_main.o repertoire.o

client: client.o
	$(CC) $(CFLAGS) -o client client.o

serveur: serveur.o
	$(CC) $(CFLAGS) -o serveur serveur.o

repertoire_main.o: repertoire_main.c repertoire.h
	$(CC) $(CFLAGS) -c repertoire_main.c

repertoire.o: repertoire.c repertoire.h
	$(CC) $(CFLAGS) -c repertoire.c

client.o: client.c client.h
	$(CC) $(CFLAGS) -c client.c

serveur.o: serveur.c serveur.h
	$(CC) $(CFLAGS) -c serveur.c

clean:
	rm -f *.o repertoire client serveur
