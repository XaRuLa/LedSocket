
//tcpclient.c
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "constants.h"


int main (int argc, char *argv[]) {

    int sockfd, rc, i, serverPort, nBytes;
    struct sockaddr_in localAddr, servAddr;
    struct hostent *h;
    char option=' ';
    char fNf='0';
    char s;

    /* Check parameters from command line */

    if(argc != 3)//check number of argc in command line
    {
        fprintf(stderr,"Usage: tcpclient [IP_server] [server_port]\n");
        return USAGE_ERR;
    }

    serverPort = atoi(argv[2]);
    if(serverPort<=0 || serverPort>65535)//check number of TCP server port
    {
        fprintf(stderr, "The port number given is wrong.\n");
        return BAD_PORT_NUM_ERR;
    }

    h = gethostbyname(argv[1]);
    if(h==NULL)//check assigment of TCP server host
    {
        perror("Unknown host ");
        return UNKNOWN_HOST_ERR;
    }

    /* Create TCP socket */
    
    servAddr.sin_family = h->h_addrtype;
    memcpy((char *) &servAddr.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
    servAddr.sin_port = htons(serverPort);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)//check TCP socket is created correctly
    {
        perror("Cannot open socket ");
        return SOCK_OPEN_ERR;
    }

    /* Bind any port number */

    localAddr.sin_family = AF_INET;
    localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    localAddr.sin_port = htons(0);

    rc = bind(sockfd, (struct sockaddr *) &localAddr, sizeof(localAddr));
    if(rc < 0)//check TCP socket is bind correctly
    {
        perror("Cannot bind on TCP port ");
        close(sockfd);
        return SOCK_BIND_ERR;
    }

    /* Connect to TCP server */

    rc = connect(sockfd, (struct sockaddr *) &servAddr, sizeof(servAddr));
    if(rc < 0)//check TCP socket is connected correctly
    {
        perror("Cannot connect ");
        close(sockfd);
        return ACC_CONN_ERR;
    }

    printf("Starting TCP client...\n");

    char buffer[BUFSIZ];

    /* Messge to respond */

    printf("Successfully Connected \n");
    return 0;
}

