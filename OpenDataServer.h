
#ifndef PROGECT_OPENDATASERVER_H
#define PROGECT_OPENDATASERVER_H

#include "Command.h"
#include "ServerSocket.h"
using namespace std;

/**
 * OpenDataServer Class
 * the class who responsible for open a server to connect with the client
 */
class OpenDataServer : public Command {
    // the port we are gonna to connect
    int port;

    //num of miliseconds we are gonna to read the information from the client
    int hz;

    //a flag that tells us id the server is running
    bool is_running;

    //
public:
    /**
     * a defult constructor
     */
    OpenDataServer();

    /**
     *
     * @param data a vector witch contains all the words from the script (command and values - expression)
     * @param index - points on a place in the data vector
     * @return how much we need to move on the array (the num of values for a specific command)
     */
    int setParameters(vector<string> data, int index) override;

    void open();

    /**
     * run the command
     */
    void doCommand() override;

    void stopListen();

    int getPort() const;

    void setPort(int port);

    int getHz() const;

    void setHz(int hz);

    struct MyParams {
        int port;
        int hz;
    };
};

#endif //PROGECT_OPENDATASERVER_H
