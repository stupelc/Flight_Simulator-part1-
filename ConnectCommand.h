
#ifndef PROGECT_CONNECTCOMMAND_H
#define PROGECT_CONNECTCOMMAND_H

#include "Command.h"

class ConnectCommand : public Command {
    string ip;
    int port;
public:
    /**
     * a defult constructor
     */
    ConnectCommand();

    const string &getIp() const;

    void setIp(const string &ip);

    int getPort() const;

    void setPort(int port);

    /**
     * a struct with the params ip and port
     */
    struct MyParams {
        string ip;
        int port;
    };

    /**
     *
     * @param data a vector witch contains all the words from the script (command and values - expression)
     * @param index - points on a place in the data vector
     * @return how much we need to move on the array (the num of values for a specific command)
     */
    int setParameters(vector<string> data, int index) override;

    /**
     * run the command
     */
    void doCommand() override;

    /**
     * destructor
     */
    ~ConnectCommand();
};

#endif //PROGECT_CONNECTCOMMAND_H
