
#include "CommandExpression.h"

/**
 *
 * @param symbolTable the table that contains all the variables in the program
 * @return the calculation of the expression
 */
double CommandExpression::calculate() {
    this->command->doCommand();
    //todo need to return double
}

/**
 *
 * @param command s command
 * constructor
 */
CommandExpression::CommandExpression(Command *command) : command(command) {}

/**
 *
 * @return the command
 */
Command *CommandExpression::getCommand() const {
    return command;
}

/**
 * destructor
 */
CommandExpression::~CommandExpression() {
    delete this->command;
}