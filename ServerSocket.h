//
// Created by chagit on 12/22/18.
//

#ifndef PROGECT_SERVERSOCKET_H
#define PROGECT_SERVERSOCKET_H

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
 * ServerSocket Class
 * opens the server
 */
class ServerSocket {
    //bool running;
public:
    static void *openSocket(void *arg);
};

#endif //PROGECT_SERVERSOCKET_H
