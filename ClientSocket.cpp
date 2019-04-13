
#include "ClientSocket.h"
#include "SymbolTable.h"
#include <netdb.h>

struct MyParams {
    string ip;
    int port;
};

/**
 *
 * @param arg
 * @return openning client socket thats connects the simulator
 */
void *ClientSocket::openSocket(void *arg) {
    struct MyParams *params = (struct MyParams *) arg;
    SymbolTable *table = SymbolTable::getInstance();

    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    portno = params->port;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //save socketid in data class
    table->setClientId(sockfd);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(params->ip.c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    table->setConnect(true);
}