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
#define BW_ITERS 500

int main(int argc, char const *argv[])
{
	int tcp_socket;
	uint16_t serverPortNum;
	struct sockaddr_in server_addr;
	const char * serverIpAddress;
	ticks time_1 = 0, time_2 = 0;
	ticks vec_setup[ITERS], vec_end[ITERS];

	if (argc < 3) {
		fprintf(stderr, "Usage %s serverIpAddress serverPortNum\n", argv[0]);
		exit(0);
	}
	serverIpAddress = argv[1];
	serverPortNum = atoi(argv[2]);

	memset(&server_addr, 0, sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	//if (inet_pton(AF_INET, serverIpAddress, &server_addr.sin_addr) <= 0) {
	if (inet_aton(serverIpAddress, &(server_addr.sin_addr)) <= 0) {
		fprintf(stderr, "Not valid IP address.\n");
		exit(0);
	}
	//server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);  // for loopback use
	server_addr.sin_port = htons(serverPortNum);

	int i;
	for (i = 0; i < BW_ITERS; i++) {
		if ((tcp_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
			fprintf(stderr, "Fail to create socket.\n");
			exit(0);
		}

		time_1 = getTime();
		int connected = connect(tcp_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
		time_2 = getTime();
		if (connected < 0)  {
			fprintf(stderr, "errno %s(%d)\n", strerror(errno), errno);
			fprintf(stderr, "ip address is %s and portno is %d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));
			fprintf(stderr, "Cannot connect to the server.\n");
			exit(0);
		}
		vec_setup[i] = time_2 - time_1;
		printf("%llu\n", vec_setup[i]);

		time_1 = getTime();
		close(tcp_socket);
		time_2 = getTime();
		vec_end[i] = time_2 - time_1;
	}


    writeLLUArray("connection_setup.txt", vec_setup, BW_ITERS);
    writeLLUArray("connection_end.txt", vec_end, BW_ITERS);

	return 0;
}
