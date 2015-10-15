all: bw_client bw_server

bw_client: bw_client.o
	gcc -o bw_client bw_client.o

bw_client.o: bw_client.c
	gcc -c -Wall bw_client.c

bw_server: bw_server.o
	gcc -o bw_server bw_server.o

bw_server.o: bw_server.c
	gcc -c -Wall bw_server.c

clean:
	rm bw_client bw_server *.o *.txt
