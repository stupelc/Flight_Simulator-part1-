
#include "ConnectCommand.h"
#include "Expression.h"
#include "Parser.h"
#include "ExpressionDetect.h"
#include "OtherFunctions.h"
#include "ClientSocket.h"
#include "SymbolTable.h"

const string &ConnectCommand::getIp() const {
    return ip;
}

void ConnectCommand::setIp(const string &ip) {
    ConnectCommand::ip = ip;
}

int ConnectCommand::getPort() const {
    return port;
}

void ConnectCommand::setPort(int port) {
    ConnectCommand::port = port;
}

/**
 * a default constructor
 */
ConnectCommand::ConnectCommand() {
    //initilize the values
    this->port = 0;
    this->ip = "";
}

/**
 *
 * @param data a vector witch contains all the words from the script (command and values - expression)
 * @param index - points on a place in the data vector
 * @return how much we need to move on the array (the num of values for a specific command)
 */
int ConnectCommand::setParameters(vector<string> data, int index) {
    this->ip = data[index + 1];
    ExpressionDetect* expressionDetect;
    string portStr = putSpaces(data[index + 2]);
    Expression *portExp = expressionDetect->evaluate(portStr);
    this->port = (int) (portExp->calculate());

    //read connect command name and two arguments
    return 3;
}

/**
 * runs the connect command
 */
void ConnectCommand::doCommand() {
    SymbolTable *table = SymbolTable::getInstance();
    table->setConnect(false);
    struct MyParams *params = new MyParams();
    params->port = this->port;
    params->ip = this->ip;

    pthread_t id;
    pthread_create(&id, nullptr, ClientSocket::openSocket, params);
}

/**
 * destructor
 */
ConnectCommand::~ConnectCommand() {
    
}