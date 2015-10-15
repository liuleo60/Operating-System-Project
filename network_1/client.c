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

// void findErrno(int errno) {
// 	switch (errno) {
// 		case EBADF: 
// 		fprintf(stderr, "The socket socket is not a valid file descriptor.\n");
// 		break; 

// 		case ENOTSOCK:
// 		fprintf(stderr, "File descriptor socket is not a socket.\n");
// 		break; 

// 		case EADDRNOTAVAIL:
// 		fprintf(stderr, "The specified address is not available on the remote machine.\n"); 
// 		break;

// 		case EAFNOSUPPORT:
// 		fprintf(stderr, "The namespace of the addr is not supported by this socket.\n");
// 		break; 

// 		case EISCONN:
// 		fprintf(stderr, "The socket socket is already connected.\n"); 
// 		break; 

// 		case ETIMEDOUT:
// 		fprintf(stderr, "The attempt to establish the connection timed out.\n");
// 		break; 

// 		case ECONNREFUSED:
// 		fprintf(stderr, "The server has actively refused to establish the connection.\n");
// 		break; 

// 		case ENETUNREACH:
// 		fprintf(stderr, "The network of the given addr isn’t reachable from this host.\n");
// 		break; 

// 		case EADDRINUSE:
// 		fprintf(stderr, "The socket address of the given addr is already in use.\n");
// 		break; 

// 		case EINPROGRESS:
// 		fprintf(stderr, "The socket socket is non-blocking and the connection could not be established immediately. You can determine when the connection is completely established with select; see Waiting for I/O. Another connect call on the same socket, before the connection is completely established, will fail with EALREADY.\n");
// 		break; 

// 		case EALREADY:
// 		fprintf(stderr, "The socket socket is non-blocking and already has a pending connection in progress (see EINPROGRESS above).\n");
// 		break; 

// 		default:
// 		break;
// 	}
// }

int main(int argc, char const *argv[])
{
	int tcp_socket, n;
	uint16_t serverPortNum;
	struct sockaddr_in server_addr;
	const char * serverIpAddress;
	ticks time_1 = 0, time_2 = 0;
	ticks vec[ITERS];

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
	fprintf(stdout, "Client: Socket created successfully.\n");

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
	fprintf(stdout, "Client: Connection completed.\n");

	char * buffer = malloc(sizeof(char)*SIZE_OF_PING);
	memset(buffer, 's', sizeof(char)*SIZE_OF_PING);
	char * ack = malloc(sizeof(char)*SIZE_OF_PING);
	int i;
	for (i = 0; i < ITERS; ++i)
	{
		time_1 = getTime();
		// Send the packet
		n = write(tcp_socket, buffer, sizeof(char)*SIZE_OF_PING);
	    if (n < 0) {
	         perror("ERROR writing to socket");
	    }
	    
	    // Receive the ACK
	    n = read(tcp_socket, ack, sizeof(char)*SIZE_OF_PING);
	    if (n < 0) {
	         perror("ERROR reading from socket");
	    }
		else if (n == 0) {
	    	fprintf(stderr, "ERROR read byte is 0, perhaps socket closed\n");
	    }
	    time_2 = getTime();

	    printf("%llu\n", time_2 - time_1);
	    vec[i] = time_2 - time_1;
	}
	
    writeLLUArray("round_trip_time.txt", vec, ITERS);
    free(buffer);
	close(tcp_socket);

	return 0;
}