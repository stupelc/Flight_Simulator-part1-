//
// Created by almogg on 12/18/18.
//

#ifndef PROGECT_VARCOMMAND_H
#define PROGECT_VARCOMMAND_H

#include "Command.h"
#include "ExpressionHeaders.h"
#include "ExpressionDetect.h"
#include "PlacementCommand.h"
#include "equalsCommand.h"

class VarCommand : public Command {
    list<Command *> listEqual = list<Command *>();
    bool isBind;
    string var;
    Expression *val;
    string path;
    string valStr;

    bool isCommandExist;
    Command *command;
public:
    VarCommand();

    ~VarCommand();

    int setParameters(vector<string> data, int index) override;

    void doCommand() override;

};

#endif //PROGECT_VARCOMMAND_H
