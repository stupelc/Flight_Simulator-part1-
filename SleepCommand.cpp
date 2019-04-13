//
// Created by chagit on 12/23/18.
//

#include "SleepCommand.h"
#include "SymbolTable.h"

//todo check if we need to do something
SleepCommand::SleepCommand() {

}

/**
 *
 * @param data the vector that contains
 * @param index the index where the data exist
 * @return the num of steps we wend in the data vector
 */
int SleepCommand::setParameters(vector<string> data, int index) {
    SymbolTable *symbolTab = SymbolTable::getInstance();
    ExpressionDetect*expressionDetect;

    //take the first and second
    //put spaces in the sleep string
    string sleepStr = putSpaces(data[index + 1]);
    Expression *sleepExp = expressionDetect->evaluate(sleepStr);
    this->sleepTime = (sleepExp->calculate() / 1000);

    //read the command name and the var of it - num of time for sleeping
    return 2;
}

/**
 * runs the sleep command
 */
void SleepCommand::doCommand() {
    //sleep the program according to the variable that we get
    sleep(this->sleepTime);
}
