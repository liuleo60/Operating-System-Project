#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> // data types for representing socket addresses in the Internet namespace
#include <netdb.h> 
#include <arpa/inet.h>  // define the function inet_pton
#include <errno.h>      // get the error number
#include "../headers/rdtsc.h"
#include "../headers/utils.h"

#define SIZE_OF_PING 56
#define SIZE_OF_MB 1024*1024
#define BW_ITERS 100

//void bandwidth_measure(int client_socket, int size_mb); // pass in the descriptor of the socket

int main(int argc, char const *argv[])
{
	int tcp_socket;
	uint16_t serverPortNum;
	struct sockaddr_in server_addr;
	const char * serverIpAddress;

	if (argc < 3) {
		fprintf(stderr, "Usage %s serverIpAddress serverPortNum\n", argv[0]);
		exit(0);
	}
	serverIpAddress = argv[1];
	serverPortNum = atoi(argv[2]);

	if ((tcp_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		fprintf(stderr, "Fail to create socket.\n");
		exit(0);
	}

	memset(&server_addr, 0, sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	//if (inet_pton(AF_INET, serverIpAddress, &server_addr.sin_addr) <= 0) {
	if (inet_aton(serverIpAddress, &(server_addr.sin_addr)) <= 0) {
		fprintf(stderr, "Not valid IP address.\n");
		exit(0);
	}
	//server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);  // for loopback use
	server_addr.sin_port = htons(serverPortNum);

	if (connect(tcp_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)  {
		fprintf(stderr, "errno %s(%d)\n", strerror(errno), errno);
		fprintf(stderr, "ip address is %s and portno is %d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));
		fprintf(stderr, "Cannot connect to the server.\n");
		exit(0);
	}

	int size_mb = 1;

	// measurement loop
	while (1) {
		int n;
		ticks time_1 = 0, time_2 = 0, sum = 0;
		ticks vec[BW_ITERS];
		
		//char * buffer = malloc(sizeof(char)*SIZE_OF_MB*size_mb);
		char buffer[SIZE_OF_MB*size_mb];
		memset(buffer, 's', sizeof(char)*SIZE_OF_MB*size_mb);
		printf("client: buffer size %lu\n", strlen(buffer));

		//char * ack = malloc(sizeof(char)*SIZE_OF_PING);
		char ack[SIZE_OF_MB*size_mb];
		memset(ack, 0, sizeof(char)*SIZE_OF_MB*size_mb);
			
		int i;
		for (i = 0; i < BW_ITERS; i++) {
			time_1 = getTime();
			n = write(tcp_socket, buffer, sizeof(char)*SIZE_OF_MB*size_mb);
			//send(tcp_socket, buffer, strlen(buffer), 0);
			if (n < 0) {
			     perror("ERROR writing to socket");
			}
			printf("client: write finished, %d btyes write.\n", n);
			
			n = read(tcp_socket, ack, sizeof(char)*SIZE_OF_PING);
			if (n < 0) {
			     perror("ERROR reading from socket");
			}
			//printf("client: read ack finished, %d btyes read.\n", n);
			
			time_2 = getTime();
			vec[i] = time_2 - time_1;
			sum += time_2 - time_1;
		}
	    printf("%llu\n", sum/BW_ITERS);

	    writeLLUArray("bandwidth_one_mb.txt", vec, BW_ITERS);
	    break;
	    //free(ack);
	    //free(buffer);
	}

	close(tcp_socket);

	return 0;
}
