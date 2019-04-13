//
// Created by almogg on 12/22/18.
//

#ifndef PROGECT_LOOPCOMMAND_H
#define PROGECT_LOOPCOMMAND_H

#include "Command.h"
#include "ExpressionHeaders.h"
#include "ExpressionDetect.h"
#include "CommandExpression.h"

class LoopCommand : public Command {
protected:
    Expression *leftExp;
    Expression *rightExp;
    string condition;
    vector<CommandExpression *> commands;
public:
    int setParameters(vector<string> data, int index) override;

    void doCommand() override;

    int createLoop(vector<string> data, int index);

    bool checkCondition();

    ~LoopCommand();
};

#endif //PROGECT_LOOPCOMMAND_H
