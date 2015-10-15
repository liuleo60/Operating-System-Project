all: client server

client: client.o
	gcc -o client client.o

client.o: client.c
	gcc -c -Wall client.c

server: server.o
	gcc -o server server.o

server.o: server.c
	gcc -c -Wall server.c

clean:
	rm client server *.o *.txt
