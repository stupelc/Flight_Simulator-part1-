//
// Created by chagit on 12/24/18.
//

#ifndef PROGECT_CLIENTSOCKET_H
#define PROGECT_CLIENTSOCKET_H

#include "string"
#include <vector>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include "string.h"
#include "Command.h"

using namespace std;

/**
 * ClientSocket Class
 * opens the client socket
 */
class ClientSocket {
public:
    /**
    *
    * @param arg
    * @return openning client socket thats connects the simulator
    */
    static void *openSocket(void *arg);
};

#endif //PROGECT_CLIENTSOCKET_H
