//tcpserver.c

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <wiringPi.h>
#include <stdlib.h>

#include "constants.h"


int main( int argc, char *argv[] )
{
    int sockfd, newsockfd, serverPort, clientLength, nBytes;;
    char buffer[BUFSIZ];
    char option=' ';
    int sent=0;
    int led = 2;
    struct sockaddr_in serverAddr, clientAddr;

/* Check parameters from command line */

    if(argc != 2){//check number of argc in command line
        fprintf(stderr,"Usage: tcpserver [server_port]\n");
        return USAGE_ERR;
    }

    printf("Starting TCP server...\n");

    serverPort = atoi(argv[1]);
    if(serverPort<=0 || serverPort>65535)//check number of TCP server port
    {
        fprintf(stderr, "The port number given is wrong.\n");
        return BAD_PORT_NUM_ERR;
    }

    /* Cara bukak tcp socket */

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)//define tcpsocket
    {
        perror("Error opening TCP socket");
        return SOCK_OPEN_ERR;
    }

    /* Initialize TCP socket structure */

    bzero((char *) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(serverPort);

    /* Bind the host address using bind() call */

    if (bind(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0)//check TCP socket is bind correctly
    {
        perror("Error on binding TCP socket");
        return SOCK_BIND_ERR;
    }

    /* Start listening for the clients, TCP server wait for the incoming TCP client connection */

    listen(sockfd, BACKLOG);
    clientLength = sizeof(clientAddr);

    /* Accept actual connection from the TCP client */

    newsockfd = accept(sockfd, (struct sockaddr *) &clientAddr, (socklen_t *) &clientLength);
    if (newsockfd < 0)//check actual connection is created correctly
    {
        perror("Error on accepting actual TCP client");
        return ACC_CONN_ERR;
    }

    /* Start communicating between TCP client and server */

    bzero(buffer,BUFSIZ);
    nBytes = read( newsockfd,buffer,BUFSIZ );
    if (nBytes < 0)
    {
        perror("Error reading from TCP socket");
        return SOCK_READ_ERR;
    }
    printf("Connected !!!\n");

	 wiringPiSetup () ;
		pinMode (led, OUTPUT);
		int i;
		for (i=0; i<10; i++)
		{
		digitalWrite (led, 1);
		delay(500);

		digitalWrite (led, 0);
		delay(500);
		}

    return 0;
}
