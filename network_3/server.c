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

	if (listen(tcp_socket, 1000) < 0) {
		fprintf(stderr, "Error listening.\n");
		exit(0);
	}

	socklen_t server_len = sizeof(server_addr);
	client_socket = accept(tcp_socket, (struct sockaddr *) &server_addr, &server_len);
	if (client_socket < 0) {
		fprintf(stderr, "Cannot accept the connection.\n");
		exit(0);
	}

	char * buffer = malloc(sizeof(char)*SIZE_OF_PING);
	while (1) {
		memset(buffer, 0, strlen(buffer));
		//time_1 = getTime();
		n = read(client_socket, buffer, strlen(buffer));
	    if (n < 0) {
	         perror("ERROR reading from socket");
	    }
	    memset(buffer, 0, strlen(buffer));
	    n = write(client_socket, buffer, strlen(buffer));
	    if (n < 0) {
	         perror("ERROR writing to socket");
	    }
	}
    //time_2 = getTime();
    //printf("%llu\n", time_2 - time_1);

    free(buffer);
    close(client_socket);
	close(tcp_socket);

	return 0;
}
