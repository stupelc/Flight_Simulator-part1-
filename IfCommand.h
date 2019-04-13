//
// Created by almogg on 12/24/18.
//

#ifndef PROGECT_IFCOMMAND_H
#define PROGECT_IFCOMMAND_H

#include "Command.h"
#include "Expression.h"
#include "CommandExpression.h"

class IfCommand : public Command {
protected:
    Expression *leftExp;
    Expression *rightExp;
    string condition;
    vector<CommandExpression *> commands;
public:
    int setParameters(vector<string> data, int index) override;

    void doCommand() override;

    int createCommands(vector<string> data, int index);

    bool checkIfCondition();

    ~IfCommand();
};

#endif //PROGECT_IFCOMMAND_H
