//
// Created by chagit on 12/23/18.
//

#ifndef PROGECT_SLEEPCOMMAND_H
#define PROGECT_SLEEPCOMMAND_H

#include "Command.h"
#include "ExpressionHeaders.h"
#include "ExpressionDetect.h"
#include "ExpressionHeaders.h"
#include "OtherFunctions.h"
#include "unistd.h"


/**
 * SleepCommand Class
 * the class who runs the sleep command
 */
class SleepCommand : public Command {
    int sleepTime;
public:
    /**
     * constructor
     */
    SleepCommand();

    /**
     *
     * @param data the vector that contains
     * @param index the index where the data exist
     * @return the num of steps we wend in the data vector
     */
    int setParameters(vector<string> data, int index) override;

    /**
     * runs the sleep command
     */
    void doCommand() override;

};

#endif //PROGECT_SLEEPCOMMAND_H
