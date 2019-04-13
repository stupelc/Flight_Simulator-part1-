
#include <iostream>
#include "OpenDataServer.h"
#include "Parser.h"
#include "Expression.h"
#include "ExpressionDetect.h"
#include "OtherFunctions.h"
#include "SymbolTable.h"

/**
 * a defult constructor
 */
OpenDataServer::OpenDataServer() {
    //initilize the values
    this->port = 0;
    this->hz = 0;
    this->is_running = false;
}

int OpenDataServer::getPort() const {
    return port;
}

void OpenDataServer::setPort(int port) {
    OpenDataServer::port = port;
}

int OpenDataServer::getHz() const {
    return hz;
}

void OpenDataServer::setHz(int hz) {
    OpenDataServer::hz = hz;
}

/**
 * run the command
 */
void OpenDataServer::doCommand() {
    SymbolTable*table=SymbolTable::getInstance();
    table->setServer(false);
    struct MyParams *params = new MyParams();
    params->port = this->port;
    params->hz = this->hz;

    open();
   // std::cout << "got here" << endl;
    pthread_t id;
    pthread_create(&id, nullptr, ServerSocket::openSocket, params);
}

/**
 *
 * @param data a vector witch contains all the words from the script (command and values - expression)
 * @param index - points on a place in the data vector
 * @return how much we need to move on the array (the num of values for a specific command)
 */
int OpenDataServer::setParameters(vector<string> data, int index) {
    ExpressionDetect*expressionDetect;
    //take the first and second
    //put spaces in the port string
    string portStr = putSpaces(data[index + 1]);
    Expression *portExp = expressionDetect->evaluate(portStr);
    this->port = (int) (portExp->calculate());

    string hzStr = putSpaces(data[index + 2]);
    Expression *hzExp = expressionDetect->evaluate(hzStr);
    this->hz = (int) (hzExp->calculate());

    //read the command name and two arguments
    return 3;
}

void OpenDataServer::open() {
    //struct MyParams *params = (struct MyParams *) arg;

    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    //initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    portno = this->port;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // now bind the host adress using bind call
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    /**
     * now start listening to teh client. here process wii go in sleep mode and will wait
     * for the incoming connection
     */
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    //accept actual connection from the client
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    SymbolTable *symbolTable = SymbolTable::getInstance();
    symbolTable->setServerId(newsockfd);
    //cout << "hii" << endl;

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
}