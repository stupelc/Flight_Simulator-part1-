
#ifndef PROGECT_COMMAND_H
#define PROGECT_COMMAND_H

#include <vector>
#include <string>
#include <map>

using namespace std;

/**
 * Command Class -
 * responsible on the command in the program
 */
class Command {
public:
    /**
     * constructor - build a new command
     */
    Command() {
    }

    /**
     *
     * @param data a vector witch contains all the words from the script (command and values - expression)
     * @param index - points on a place in the data vector
     * @return how much we need to move on the array (the num of values for a specific command)
     */
    virtual int setParameters(vector<string> data, int index) = 0;

    /**
     * the function that runs the command we want
     */
    virtual void doCommand() = 0;

   // virtual ~Command();
};

#endif //PROGECT_COMMAND_H
