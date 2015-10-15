#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> // data types for representing socket addresses in the Internet namespace
#include <netdb.h> 
#include "../headers/rdtsc.h"
#include "../headers/utils.h"

#define SIZE_OF_PING 56
#define SIZE_OF_MB 1024*1024
#define BW_ITERS 100

int main(int argc, char const *argv[])
{
	int tcp_socket, client_socket, n;
	uint16_t serverPortNum;
	struct sockaddr_in server_addr;
	//char * serverIpAddress
	//ticks time_1 = 0, time_2 = 0;

	if (argc < 2) {
		fprintf(stderr, "Usage %s serverPortNum\n", argv[0]);
		exit(0);
	}
	//serverIpAddress = argv[1];
	serverPortNum = atoi(argv[1]);

	if ((tcp_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		fprintf(stderr, "Fail to create socket.\n");
		exit(0);
	}

	memset(&server_addr, 0, sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	//server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // for loopback use
	server_addr.sin_port = htons(serverPortNum);

	if (bind(tcp_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
		fprintf(stderr, "Cannot bind to the socket.\n");
		exit(0);
	}

	if (listen(tcp_socket, 5) < 0) {
		fprintf(stderr, "Error listening.\n");
		exit(0);
	}

	socklen_t server_len = sizeof(server_addr);
	client_socket = accept(tcp_socket, (struct sockaddr *) &server_addr, &server_len);
	if (client_socket < 0) {
		fprintf(stderr, "Cannot accept the connection.\n");
		exit(0);
	}

	int size_mb = 1;
	char * ack = malloc(sizeof(char)*SIZE_OF_PING);
	memset(ack, 'a', sizeof(char)*SIZE_OF_PING);

	while (1) {
		char * buffer = malloc(sizeof(char)*SIZE_OF_MB*size_mb);
		//memset(buffer, 0, sizeof(char)*SIZE_OF_MB*size_mb);

		int i;
		for (i = 0; i < BW_ITERS; i++) {
			n = read(client_socket, buffer, sizeof(char)*SIZE_OF_MB*size_mb);
		    if (n < 0) {
		         perror("ERROR reading from socket");
		    }

	    	n = write(client_socket, ack, sizeof(char)*SIZE_OF_PING);
		    if (n < 0) {
		         perror("ERROR writing to socket");
		    }
		}
		free(buffer);
	}
    
    //printf("%llu\n", time_2 - time_1);
    free (ack);
    close(client_socket);
	close(tcp_socket);

	return 0;
}
