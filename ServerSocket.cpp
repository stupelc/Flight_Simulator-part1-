//
// Created by chagit on 12/22/18.
//

#include <iostream>
#include <sstream>
#include "ServerSocket.h"
#include "SymbolTable.h"


using namespace std;

struct MyParams {
    int port;
    int hz;
};

void *ServerSocket::openSocket(void *arg) {
    char buffer[1024];
    bool running = true;
    //if connections is established then start communicating
    bzero(buffer, 1024);
    SymbolTable *symbolTab = SymbolTable::getInstance();
    int n;

    string buff = "";
    string leftOvers = "";

    SymbolTable *table = SymbolTable::getInstance();
    vector<string> paths = table->getNames();
    //sleep fot this->hz
    while (running) {

        bzero(buffer, 256);
        n = read(table->getServerId(), buffer, 255);
        if (n < 0) {
            perror("ERROR reading from socket");
            running = false;
           // exit(1);
        }

       // buff = buff.substr(1,buff.size()-2); //take out the quats
        // split each line it get from the file to list of separate strings
        vector<string> info;
        size_t pos = 0;
        string delimiter = ",";
        string delimiter2 = "\n";
        buff += buffer;
        pos = buff.find(delimiter2);
        leftOvers += buff.substr((0, pos));

        // to remove the \n from the beginning of the string
        leftOvers = leftOvers.substr(1);
        buff.erase(pos + delimiter2.length() - 1);
        pos = 0;
        while ((pos = buff.find(delimiter)) != string::npos) {
            info.push_back(buff.substr(0, pos));
            buff.erase(0, pos + delimiter.length());
        }
        info.push_back(buff.substr(0, pos));
        buff = "";

        for (int i = 0; i < paths.size(); ++i) {
            table->addValueByPathIndex(i, stod(info[i]));
        }
        table->setValuesInSymbolTable();

        buff += leftOvers;
        leftOvers = "";

    }

    //todo - maybe close thread ?
//    table->setServer(true);
}
