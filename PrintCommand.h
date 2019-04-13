
#ifndef PROGECT_PRINTCOMMAND_H
#define PROGECT_PRINTCOMMAND_H


#include "Command.h"
#include "ExpressionHeaders.h"
#include "ExpressionDetect.h"
#include "ExpressionHeaders.h"
#include "OtherFunctions.h"
#include "unistd.h"
#include <string>

using namespace std;

/**
 * PrintCommand Class
 * runs the print command
 */
class PrintCommand : public Command {
    string printStr;
    bool isString;

public:
    /**
     * constructor
     */
    PrintCommand();

    /**
     *
     * @param data a vector witch contains all the words from the script
     * @param index - points on a place in the data vector
     * @return how much we need to move on the array
     */
    int setParameters(vector<string> data, int index) override;

    /**
     * runs the command
     */
    void doCommand() override;
};

#endif //PROGECT_PRINTCOMMAND_H
